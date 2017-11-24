<?php


if(empty($option)) {
	include "html/usermgr.phtml";	

}else{
	switch($option) {
		case "add":
			include "include/useradd.php";
		break;
		case "del":
			include "include/userdel.php";
		break;
	}
}

?>
