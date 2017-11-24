<?php


if(empty($_GET['option'])) {
	include "html/listsmgr.phtml";	

}else{
	switch($_GET['option']) {
		case "add":
			include "include/listsadd.php";
		break;
		case "del":
			include "include/listsdel.php";
		break;
	}
}

?>
