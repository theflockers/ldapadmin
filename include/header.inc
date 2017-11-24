<html>
 <head>
  <title>.::LDAP Mail Manager::.</title>
  <link type="text/css" rel="StyleSheet" href="style/default/style.css" />
 </head>
 <script language="JavaScript" src="js/scripts.js"></script>
  <div id="form0">
   <div id="logo" ><img src="images/topo.png"/></div>

  <table width="100%" border="0">
   <tr>
    <td width="170">&nbsp;</td>
    <td width="200">
	<!-- Botao Adicionar -->
	<?php

	  switch($_GET['menuopt']){

		case "usr":
			$link="useradd.phtml";
			$title="Adicionar usu&aacute;rio";
		break;
		case "alias":
			$link="aliasadd.phtml";
			$title="Adicionar alias";
		break;
		case "lists":
			$link="listsadd.phtml";
			$title="Adicionar lista";
		break;
	}
	if (isset($_SESSION['username'])) {
		include "include/menuadm.inc";	
	}
	?>
  </table>
