<?php

$info['cn'] = $_POST['username'];
$info['sn'] = $_POST['surename'];
$info['uid'] = $_POST['username'];
$info['homeDirectory'] = homeparse($_POST['username'],$_POST['domain']);
$info['mailQuota'] = ($_POST['quota'] * 1024) * 1024;
$info['mailMessageStore'] = homeparse($_POST['username'],$_POST['domain'])."/Maildir/";

?>
