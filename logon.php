<?

session_start();

require_once("config/config.php");
require_once("include/functions.php");
//require_once("class.php");	
require_once("include/ldap_connection.inc");

if(!isset($_SESSION['username'])) {

	if($_POST['username']!="admin") {

		$authinfo=explode("@",$_POST['username']);
		$bind_username=user_dnparse($authinfo[0],$authinfo[1]).",ou=Domains,".$config['ldapdn'];

	}else{

		$bind_username="cn=".$_POST['username'].",".$config['ldapdn'];

	}
	if(@ldap_bind($conn,$bind_username,$_POST['password'])){

		$filter="(&(objectClass=dnsdomain)(associateddomain=".$authinfo[1]."))";

		$dsearch=ldap_search($conn,"ou=Domains,".$config['ldapdn'],$filter,$attr=array("mailquota","associateddomain","description","mailaccounts"));
		$domainobject=ldap_get_entries($conn,$dsearch);

		$_SESSION['username']=$_POST['username'];
		$_SESSION['domain']=$authinfo[1];
		$_SESSION['password']=$_POST['password'];
		$_SESSION['bind_username']=$bind_username;
		$_SESSION['mailquota']=$domainobject[0]['mailquota'][0];
		$_SESSION['mailaccounts']=$domainobject[0]['mailaccounts'][0];

		//$_URL=ereg_replace("http","https",$_SERVER['HTTP_REFERER']);
		$_URL=$_SERVER['HTTP_REFERER'];
//		header("location: ".$_SERVER['HTTP_REFERER']);
		header("location: ".$_URL);
	}else{
//		include("include/login_form.inc");
		header("location: index.php?err");
	//	exit;
	}
}else{
	@ldap_bind($conn,$_SESSION['bind_username'],$_SESSION['password']);
//	header("location: ".$_SERVER['HTTP_REFERER']);
}


?>
