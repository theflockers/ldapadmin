<?php

/*
$info['objectClass'][0] = "top";
$info['objectClass'][1] = "person";
$info['objectClass'][2] = "domainRelatedObject";
$info['objectClass'][3] = "inetMailUser";
$info['objectClass'][4] = "posixAccount";
$info['cn'] = $_POST['username'];
$info['sn'] = $_POST['surename'];
$info['uid'] = $_POST['username'];
$info['gidNumber'] = $config['defaultUID'];
$info['uidNumber'] = $config['defaultUID'];
$info['homeDirectory'] = homeparse($_POST['username'],$_POST['domain']);
$info['mailHost'] = $config['mailHost'];
$info['mailQuota'] = ($_POST['quota'] * 1024) * 1024;
$info['inetMailUserVersion'] = 0;
$info['inetMailUserStatus'] = $config['defaultStatus'];
$info['associatedDomain'] = $_POST['domain'];
$info['mailMessageStore'] = homeparse($_POST['username'],$_POST['domain'])."/Maildir/";
$info['userPassword'] = "{crypt}".crypt($_POST['password']);
$info['CourierUserCode'] = cou */

# suporte, lmendes, com, br, Lists, Mail, lmendes
#cn=suporte,dc=lmendes,dc=com,dc=br,ou=Lists,ou=Mail,o=lmendes

$info['objectClass'][0] = "top";
$info['objectClass'][1] = "inetMailGroup";
$info['objectClass'][2] = "inetOrgPerson";
$info['objectClass'][3] = "domainRelatedObject";
$info['cn'] = $_POST['cn'];
$info['sn'] = $_POST['sn'];
$info['moderator'] = "postmaster@".$_SESSION['domain'];
$info['requestsTo'] = $_POST['cn']."-request@".$_SESSION['domain'];
$info['inetMailGroupVersion'] = "0";
$info['mailForwardingAddress'] = $_POST['cn']."-".$_SESSION['domain'];
$info['mail'] = $_POST['mailforwardingaddress'];
$info['associatedDomain'] = $_SESSION['domain'];

?>
