<?php

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
$info['CourierUserCode'] = courieruid();

?>
