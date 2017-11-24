<?php
//if($_GET['action']=="logout") {
//}
session_start();

//require_once("include/login_prompt.inc");
if($_GET['action']=="out"){
	session_destroy();
	header("location: http://".$_SERVER['SERVER_NAME']."/index.php");
}

if(!isset($_SESSION['username'])){
	include "include/login_form.inc";
}else{
	require_once("include/functions.php");
	require_once("config/config.php");
	require_once("include/header.inc");
	require_once("include/main.php");
}

?>
