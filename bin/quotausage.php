#!/usr/bin/php
<?php

if($argc!=2) {
	echo "Missing maildir\n";
	exit;
} 

$file=$argv[1]."maildirsize";

if(!file_exists($file)) {
	return "Arquivo inexistente";
	exit;
}
$fp=fopen($file,"r");

while(!feof($fp)) {
	$str=fgets($fp,80);

	$msg=substr($str,0,15); // Get the first 15 characters

	$msg=trim($msg); // Clear white spaces
	if(preg_match("/.*S/",$msg)) {
//		echo $msg;
       	        $totalquota=substr($msg,0,(strlen($msg)-1));
//		echo strlen($msg)-2;
        }
	elseif(preg_match('/^-/',$msg)) {
		
		$oper=substr($msg,1,10);

//		echo "$quota - $oper\n";
		$quota=($quota-$oper);
//		echo "Quota = $quota\n";*/
	}else{
		$oper=$msg;

//		echo "$quota + $oper\n";
		$quota=($quota+$oper);
//		echo "Quota = $quota\n";*/
	}
}
//echo $totalquota;
$quotausage=round(($quota * 100 / $totalquota));

echo $quotausage." ".$quota." ".$totalquota;

?>
