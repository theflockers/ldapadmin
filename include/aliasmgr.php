<?php


if(empty($_GET['option'])) {
	include "html/aliasmgr.phtml";	

}else{
	switch($_GET['option']) {
		case "add":
			include "include/aliasadd.php";
		break;
		case "del":
			include "include/aliasdel.php";
		break;
	}
}

?>
