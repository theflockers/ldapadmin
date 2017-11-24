<?php	

include "config/config.php";
include "include/ldap_connection.inc";
include "logon.php";

include "include/header_noimg.inc";

/* Extrai o nome da Lista*/
$cn=explode(',',substr($_GET['dn'],'3'));

/* Sufixo das listas */
$suffix=array(
	0 => 'owner',
	1 => 'request',
	2 => 'approval');

/* Remove endereços relacionados a lista */
for($i=0;$i<count($suffix);$i++) {
	@ldap_delete($conn,str_replace($cn[0],$cn[0]."-".$suffix[$i],$_GET['dn']));
}

/* Remove lista-owner */
@ldap_delete($conn,str_replace($cn[0],$suffix[0]."-".$cn[0],$_GET['dn']));

/* Remove a lista em si */
@ldap_delete($conn,$_GET['dn']);

$res=ldap_errno($conn);

echo "<script>
			location='?menuopt=lists';
		</script>";
?>
