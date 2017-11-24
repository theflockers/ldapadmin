<?php

	if(!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="Acesso restrito ao(s) Administrador(es)"');
		header('HTTP/1.0 401 Unauthorized');
		echo "Acesso Negado. Digite corretamente seu usu&aacute;rio e senha";
	 	exit;
	}else{
		require_once("config/config.php");
		require_once("functions.php");
		require_once("class.php");	
		require_once("include/ldap_connection.inc");

		if($_SERVER['PHP_AUTH_USER']!="admin") {

			$authinfo=explode("@",$_SERVER['PHP_AUTH_USER']);
			$http_username=user_dnparse($authinfo[0],$authinfo[1]).",ou=Domains,".$config['ldapdn'];

		}else{

			$http_username="cn=".$_SERVER['PHP_AUTH_USER'].",".$config['ldapdn'];
	
		}
		if(@ldap_bind($conn,$http_username,$_SERVER['PHP_AUTH_PW'])){
			$_SESSION['user']=$_SERVER['PHP_AUTH_USER'];
			$_SESSION['domain']=$authinfo[1];
		}else{
	                header('WWW-Authenticate: Basic realm="Acesso restrito ao(s) Administrador(es)"');
			header('HTTP/1.0 401 Unauthorized');
	 		exit;
			//$_SESSION['user']="Anonymous";
		}
	}


?>
