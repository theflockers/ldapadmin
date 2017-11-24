<?php	

include "config/config.php";
include "include/ldap_connection.inc";
include "logon.php";
//include "include/functions.php";

include "include/header_noimg.inc";

@ldap_delete($conn,$_GET['dn']);
$res=ldap_errno($conn);

if($res==66){
	echo "<script>alert('Nao e possivel excluir um dominio com objetos filhos, exclua-os primeiro')</script>";
}
echo "<script>
			location='?menuopt=usr&&domain=".$_GET['domain']."';
		</script>";

	
?>
