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
$info['CourierUserCode'] = courieruid();*/

$info['objectClass'][0] = "top";
$info['objectClass'][1] = "inetMailUser";
$info['objectClass'][2] = "inetOrgPerson";
$info['objectClass'][3] = "domainRelatedObject";
$info['cn'] = $pieces[0];
$info['sn'] = $_POST['sn'];
$info['inetMailUserVersion'] = 1;
$info['mailHost'] = $config['mailHost'];
$info['mailForwardingAddress'] = $_POST['mailforwardingaddress'];
$info['associatedDomain']= $_SESSION['domain'];
$info['mail'] = $_POST['mail'];

?>
