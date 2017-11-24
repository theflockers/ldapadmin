<?php


include "include/ldap_connection.inc";

	if($_SESSION['user']=="admin") {

		$ds=ldap_search($conn,"ou=Aliases,".$config['ldapdn'],"(objectClass=dnsDomain)",$attr=array("associateddomain","description"));

	} else {

		$ds=ldap_search($conn,"ou=Aliases,".$config['ldapdn'],"(&(objectClass=dnsDomain)(associatedDomain=".$_SESSION['domain']."))",$attr=array("associateddomain","description"));

	}

	ldap_sort($conn,$ds,"associateddomain");
	$domainobject=ldap_get_entries($conn,$ds);
	echo ' <tr id="aliases">';	
	echo "  <td colspan=\"2\">\n";
	echo "   <div style=\"padding-left: 20px;\">\n";

	for($z=0;$z<count($domainobject);$z++) {
	   
		$domain=$domainobject[$z]['associateddomain'];		

		if($domain) {

			echo "<img src=\"images/ProtectBlue.png\" align=\"top\"/>&nbsp;<a onmouseover=\"focus()\"";

			if($_GET['domain']==$domain[0]){
				echo "style=\"background-color: #eee; border: dotted 1px #555;\"";
			}

			echo "id=\"$z\" onclick=\"openlocation('?menuopt=alias&&domain=".$domainobject[$z]['associateddomain'][0]."','".$z."')\" class=\"menuitem\" onmousedown=\"rightmenu(event,'".$z."','pop".$z."')\" >".$domainobject[$z]['associateddomain'][0]."<br/>";

			/* Menu botao direito */
       
			echo "<div class=\"rightmenu_alias\" onclick=\"showmenu('pop".$z."')\" id=\"pop$z\" style=\"position: absolute; top: 0px; left: 0px; background-color: #eeeeee; visibility: hidden\" >\n";

			
			/* Habilita exclusao de dominio somente se form admin */
			if($_SESSION['user']=="admin") {		

				echo "  <a class=\"rightmenu_alias\" onclick=\"asktodo('index.php?menuopt=del&&domain=".$_GET['domain']."&&dn=".$domainobject[$z]['dn']."','Deseja excluir o dominio ".$_GET['domain']."?')\"><img src=\"images/spacer.png\" align=\"middle\">Remover dom&iacute;nio</a><br/>\n";

			}
			
			echo "  <a class=\"rightmenu_alias\" onclick=\"openwin('aliasadd.phtml?domain=".$domainobject[$z]['associateddomain'][0]."','add','".$z."')\"><img src=\"images/spacer.png\" align=\"middle\">Novo alias</a><br/>\n";
				echo "  <a class=\"rightmenu\" onclick=\"openwin('property.phtml?obj=domain&&dn=".$domainobject[$z]['dn']."','prop','".$z."')\"><img src=\"images/spacer.png\" align=\"middle\">Propriedades</a>\n";
			echo "</div>\n";
		}	
	}
	echo "   </div>\n";
	echo "  </td>\n";
	echo " </tr>\n";	

?>
