<?php

// User Information
$info['cn']	= $_POST['username'];
$info['sn']	= $_POST['surename'];
$info['uid']	= $_POST['username'];


// AutoReply Information
$info['mailAutoReplySubject']		= $_POST['mailAutoReplySubject'];
$info['mailAutoReplyText']		= $_POST['mailAutoReplyText'];
$info['mailAutoReplySubject']		= $_POST['mailAutoReplySubject'];
$info['mailAutoReplyStartDate'] 	= date("U");
$info['mailAutoReplyExpirationDate']	= 0;
?>
