#!/usr/bin/php
<?php

// argv[1] = HOME

$file=$argv[1]."/.mailfilter";
$forward = $argv[2];


if(!isset($argv[1])) {
	print "Diretorio pessoal não existe\n";
	exit;
}

if(!isset($argv[2])) {
	print "Faltando e-mail para forwarding\n";
	exit;
}

if(file_exists($file)) {
	print "Redirecionamento já existe, sobrepondo...\n";
}

if($fp=fopen($file,w)) {
	fputs($fp,"logfile maildrop.log\nto \"!".$forward."\"\n");	
}

chown($file,200);
chgrp($file,200);
exec("chmod 600 $file");


?>
