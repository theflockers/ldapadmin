<a onclick="openwin('<? echo $link;?>?domain=<? echo $_SESSION['domain']; ?>','add','0'); "><img id="btn_add" src="images/menu_01.gif" align="middle" title="<? echo $title;?>" /></a>

	<img src="images/menu_04.gif" align="middle"/>

	<!-- Botao Search -->
        <img id="btn_search" onclick="alert('Função não habilitada')" src="images/menu_02.gif" align="middle" title="Busca"/>

	<img src="images/menu_04.gif" align="middle"/>

	<!-- Botao Propriedades -->
        <a onclick="openwin('property.phtml?obj=domain&&dn=<? echo domain_dnparse($_SESSION['domain'].",ou=Domains,".$config['ldapdn']); ?>','prop','0'); "><img id="btn_search" src="images/menu_00.gif" align="middle" border="0" title="Propriedades"/></a>

	<img src="images/menu_04.gif" align="middle"/>

	<!-- Botao Sair -->
        <a onclick=location="index.php?action=out"><img id="btn_out" src="images/menu_03.gif" align="middle" border="0" title="Sair" /></a>
    </td>
    <td width="100"> Quota usage:</td>
    <td width="100" ><div style="border: solid 1px #555; width: 100px;">
	<?php
		if(file_exists("images/cache/".$_SESSION['domain']."_usage.png")) {
			echo "<img src='images/cache/".$_SESSION['domain']."_usage.png' align='middle'/>";
		}
		echo "<img src='images/cache/".$_SESSION['domain']."_avaliable.png' align='middle'/> ";

	?></div>
    </td>
    <td width="80"><b><?  echo round(($_SESSION['mailquota']/1024/1024)); ?> MB </b> </td>

   </tr>

