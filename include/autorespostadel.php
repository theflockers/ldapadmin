<?php	

include "config/config.php";
include "include/ldap_connection.inc";
include "logon.php";
//include "include/functions.php";

include "include/header_noimg.inc";

$info['mailautoreplytext']		= array();
$info['mailautoreplysubject']		= array();
$info['mailautoreplystartdate'] 	= array();
$info['mailautoreplyexpirationdate']	= array();


/* Geeting the user home Directory from LDAP*/
$search=ldap_search($conn,$_GET['dn'],'(objectClass=*)',array("homedirectory"));
$entries=ldap_get_entries($conn,$search);

/*echo "<script>alert('".$entries[0]['homedirectory'][0]."')</script>";*/
$homedir=$entries[0]['homedirectory'][0];

@ldap_mod_del($conn,$_GET['dn'],$info);
$res=ldap_errno($conn);

if($res==66){
	echo "<script>alert('Nao e possivel excluir um dominio com objetos filhos, exclua-os primeiro')</script>";
}
exec("sudo bin/cancelredir.php ".$homedir);
echo "<script>
			alert('Auto Resposta excluida');
			location='?menuopt=usr&&domain=".$_GET['domain']."';
		</script>";

	
?>
