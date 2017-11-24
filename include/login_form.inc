<?php

	require_once("include/functions.php");
	require_once("config/config.php");
	require_once("include/header.inc");
//	require_once("include/main.php");

?>
<div align="center" style="width: 300px; margin-left: auto; margin-right: auto;" >
 <div>
  <form name="login_prompt" method="POST" action="logon.php" >
 <table border="0" cellpadding="2" >
  <tr>
   <td colspan="2" class="coltitle">Bem vindo ao EasyMail! </td>
  </tr>
  <tr>
   <td colspan="2">&nbsp;</td>
  </tr>
  <tr>
   <td>Login: </td>
   <td><input type="text" name="username" /> </td>
  </tr>
  <tr>
   <td>Senha: </td>
   <td><input type="password" name="password" /> </td>
  </tr>
  <tr>
   <td colspan="2" style="text-align: center; color: #f00; font-weight: bold">&nbsp; <? if(isset($_GET['err'])) echo "Usu&aacute;rio ou senha inv&aacute;lidos"; ?> </td>
  </tr>
  <tr>
   <td colspan="2" align="center" style="padding: 5px;" >
	<input class="button" type="submit" value="Acessar" />
        <input class="button" type="reset" value="Corrigir" />
    </td>
  </tr>
 </table>
  </form>
 </div>
</div>
