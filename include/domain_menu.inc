<?php

include "include/ldap_connection.inc";

	if($_SESSION['user']=="admin") {

		$ds=ldap_search($conn,"ou=Domains,".$config['ldapdn'],"(objectClass=dnsDomain)",$attr=array("associateddomain","description"));

	} else {

		$ds=ldap_search($conn,"ou=Domains,".$config['ldapdn'],"(&(objectClass=dnsDomain)(associatedDomain=".$_SESSION['domain']."))",$attr=array("associateddomain","description"));

	}

	ldap_sort($conn,$ds,"associateddomain");
	$domainobject=ldap_get_entries($conn,$ds);
	echo ' <tr id="domains">';	
	echo "  <td colspan=\"2\">\n";
	echo "   <div style=\"padding-left: 0px;\">\n";

	for($z=0;$z<count($domainobject);$z++) {
	   
		$domain=$domainobject[$z]['associateddomain'];		

		if($domain) {

			echo "<img src=\"images/ProtectBlue.png\" align=\"top\"/>&nbsp;<a onmouseover=\"focus()\"";

//			if($_SESSION['domain']==$domain[0]){
//				echo "style=\"background-color: #eee; border: dotted 1px #555;\"";
//			}

//			echo "id=\"$z\" onclick=\"openlocation('?menuopt=usr&&domain=".$domainobject[$z]['associateddomain'][0]."','".$z."')\" class=\"menuitem\" onmousedown=\"rightmenu(event,'".$z."','pop".$z."')\" >".$domainobject[$z]['associateddomain'][0]."<br/>";
//			echo "id=\"$z\" onclick=\"openlocation('?menuopt=usr&&domain=".$domainobject[$z]['associateddomain'][0]."','".$z."')\" class=\"menuitem\" >".$domainobject[$z]['associateddomain'][0]."<br/>";
			echo "id=\"$z\" class=\"menuitem\" >".$domainobject[$z]['associateddomain'][0]."<br/>";

			/* Menu botao direito */
       
			echo "<div class=\"rightmenu_domain\" id=\"pop$z\" style=\"position: absolute; top: 0px; left: 0px; background-color: #eeeeee; visibility: hidden\" >\n";
//			echo "<div class=\"rightmenu_domain\" onclick=\"showmenu('pop".$z."')\" id=\"pop$z\" style=\"position: absolute; top: 0px; left: 0px; background-color: #eeeeee; visibility: hidden\" >\n";

			
			/* Habilita exclusao de dominio somente se form admin */
			if($_SESSION['user']=="admin") {		

				echo "  <a class=\"rightmenu\" onclick=\"asktodo('index.php?menuopt=del&&domain=".$_SESSION['domain']."&&dn=".$domainobject[$z]['dn']."','Deseja excluir o dominio ".$_SESSION['domain']."?')\"><img src=\"images/spacer.png\" align=\"middle\">Remover dom&iacute;nio</a><br/>\n";

			}
			
			echo "  <a class=\"rightmenu\" onclick=\"openwin('useradd.phtml?domain=".$domainobject[$z]['associateddomain'][0]."','add','".$z."')\"><img src=\"images/spacer.png\" align=\"middle\">Novo usu&aacute;rio</a><br/>\n";
				echo "  <a class=\"rightmenu\" onclick=\"openwin('property.phtml?obj=domain&&dn=".$domainobject[$z]['dn']."','prop','".$z."')\"><img src=\"images/spacer.png\" align=\"middle\">Propriedades</a>\n";
			echo "</div>\n";
		}	
	}
	echo "   </div>\n";
	echo "  </td>\n";
	echo " </tr>\n";	

echo ' <tr> 
  <td style="padding-left: 8px;" align="right"><img src="images/Repair.png" align="bottom" /></td>
  <td><a id="usrdom" class="linktitle" onclick=location="?menuopt=usr">Usu&aacute;rios</a ></td>
 </tr>
 <tr>
  <td style="padding-left: 8px;" align="right"><img src="images/Repair.png"/ </td>
   <td><a id="aliasmenu" class="linktitle" onclick=location="?menuopt=alias">Aliases</a></td> 
 </tr>
 <tr>
  <td style="padding-left: 8px;" align="right"><img src="images/Repair.png"/ ></td>
   <td><a id="listsmenu" class="linktitle" onclick=location="?menuopt=lists">Listas</a></td> 
 </tr>';



?>
