#!/usr/bin/php
<?php

// argv[1] = HOME

if(!isset($argv[1])) {
	print "Diretorio pessoal não existe\n";
	exit;
}

if(!isset($argv[2])) {
	print "No subject provided\n";
	exit;
}

if(!isset($argv[3])) {
	print "No source file provided\n";
	exit;
}

$home	 =	$argv[1];
$file	 =	$argv[1]."/.mailfilter";
$subject =	$argv[2];
$message = 	$argv[3];

if(file_exists($file)) {
	print "Redirecionamento já existe, sobrepondo...\n";
}

copy($message,$home."/.msg.eml");

$script .= "# Auto Resposta\n";
$script .= "cc \"|mailbot -t .msg.eml -A 'Subject: $subject' /usr/sbin/sendmail -t -f \$LOGNAME\"\ \n";

if($fp=fopen($file,w)) {
	fputs($fp,$script);	
}

chown($file,200);
chgrp($file,200);
exec("chmod 600 $file");


?>
