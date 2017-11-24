#!/usr/bin/php
<?php

// argv[1] = HOME

$file=$argv[1]."/.mailfilter";
//$forward = $argv[2];
/*
if(!isset($argv[1])) {
	print "Diretorio pessoal não existe\n";
	exit;
}*/

unlink($file);

?>
