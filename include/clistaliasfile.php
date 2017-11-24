<?php

session_start();


/* Include config, connection and logon */ 
include "config/config.php";
include "include/ldap_connection.inc";
include "logon.php";

define("TEMPFILE","/mail/lists/majordomo-aliases"); /* Majordomo aliases file */
define("HOMEDIR","/mail/lists");		    /* Majordomo list directory */

$filter="(objectClass=inetMailGroup)"; /* Get only InetMailGroup Objects */

/* Query */
//$usearch=ldap_search($conn,domain_dnparse($_SESSION['domain']).",ou=Lists,".$config['ldapdn'],$filter,$attr=array("cn","associateddomain","mailforwardingaddress","mail","requestsTo","rfc822mailmember"));
$usearch=ldap_search($conn,"ou=Lists,".$config['ldapdn'],$filter,$attr=array("cn","associateddomain","mailforwardingaddress","mail","requestsTo","rfc822mailmember"));

ldap_sort($conn,$usearch,"cn"); /* Sort by cn */
$userobject=ldap_get_entries($conn,$usearch);

//echo '<pre>';
//print_r($userobject);

/* unlink majordomo aliases file */
@unlink(TEMPFILE);

/* If the file could not be opened.. */
if(!$fp=fopen(TEMPFILE,"w")) {
	print("Erro ao abrir arquivo");
}else{
	/* Fetching all objects */
	for($i=0;$i<$userobject['count'];$i++) {

		$ListInfo['name']=$userobject[$i]['cn'][0];
		$ListInfo['domain']=$userobject[$i]['associateddomain'][0];
		$ListInfo['forwarding']=$userobject[$i]['mailforwardingaddress'][0];
		
//		echo "<script>alert('".$ListInfo['name']."')</script>"; 	

		$ListFile=HOMEDIR."/".$ListInfo['domain']."/lists/".$ListInfo['name'];
		@unlink($ListFile);

//		echo "<script>alert('".$ListFile."')</script>"; 	
		$fp_list=fopen($ListFile,"a");

		/* Populating list mail file */
		if(count($userobject[$i]['rfc822mailmember'])!=0) {
			foreach($userobject[$i]['rfc822mailmember'] as $member) {
				if(!is_int($member)) {
				// 	echo "<script>alert('$member')</script>"; 	
					fputs($fp_list,$member."\n");
				}
			}
		}
		chmod($ListFile,0664);
		/* close list mail file */
		fclose($fp_list);
		include "templates/majordomo-aliases.inc";

		fputs($fp,$content);
	}
}
/* close file majordomo alias file*/
fclose($fp);
exec("sudo newaliases");

?>
