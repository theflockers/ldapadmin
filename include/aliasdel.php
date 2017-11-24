<?php	

include "config/config.php";
include "include/ldap_connection.inc";
include "logon.php";

include "include/header_noimg.inc";

@ldap_delete($conn,$_GET['dn']);
$res=ldap_errno($conn);


echo "<script>
			location='?menuopt=alias';
		</script>";
	
?>
