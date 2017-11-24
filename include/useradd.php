<?php

include "include/functions.php";


switch($action) {
	case "":
		include "html/useraddform.phtml";
	break;
	case "add":
		$userdn=user_dnparse($_POST['username'],$_POST['domain']).",ou=Domains,".$config['ldapdn'];

		include "templates/inetmailuser.inc";


		$ret=ldap_add($conn,$userdn,$info);
		if($ret){
			echo "Usuario adicionado com sucesso";
		}else{
			echo $ret;
		}
	break;
}

?>
