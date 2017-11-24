<?php

function homeparse($user,$domain) {

	include "/var/www/ldapadmin/config/config.php";
	$pieces=explode(".",$domain);
	
	if(count($pieces)<4 ) return $config['mailhome']."$domain/$user";
		else
			return $config['mailhome']."$pieces[1].$pieces[2].$pieces[3]/$pieces[0]/$user";	
}


function user_dnparse($user,$domain) {
	$pieces=explode(".",$domain);
	
	if(count($pieces)>3 ) return "cn=$user,dc=$pieces[0],dc=$pieces[1],dc=$pieces[2],dc=$pieces[3]";
	elseif(count($pieces)<3)
		return "cn=$user,dc=$pieces[0],dc=$pieces[1]";
	else
		return "cn=$user,dc=$pieces[0],dc=$pieces[1],dc=$pieces[2]";
}

function domain_dnparse($domain) {
	$pieces=explode(".",$domain);
	
	if(count($pieces)>3 )  {
			return "dc=$pieces[0],dc=$pieces[1],dc=$pieces[2],dc=$pieces[3]";
	}	elseif(count($pieces)<3) {
		   return "dc=$pieces[0],dc=$pieces[1]";
	}else {
			return "dc=$pieces[0],dc=$pieces[1],dc=$pieces[2]";
   }
}

function randomkeys($length)
  {
   $pattern = "1234567890abcdef1234567890abcdef1234";
   for($i=0;$i<$length;$i++)
   {
     $key .= $pattern{rand(0,35)};
   }
   return $key;
  }

function courieruid() {
  return randomkeys(8)."-".randomkeys(4)."-".randomkeys(4)."-".randomkeys(12);
}

function printquota($perc,$user) {


	$fface="fonts/arial_bold.ttf";
	$fsize="9";

	if($perc>100) {

		$im=@imagecreatefrompng("images/red.png");
		$im_new=@imagecreatetruecolor(100,15);

//		$red=@imagecolorallocate($im,255,0,0);
		$textcolor=@imagecolorallocate($im,0xff,0xff,0xff);
		@imagettftext($im,$fsize,0,7,11,$textcolor,"$fface","Acima da Quota");
		@imagecopyresampled($im_new,$im,0,0,0,0,100,15,100,15);
		@imagepng($im_new,"images/cache/".$user."_usage.png");
		@imagedestroy($im);
		return 1;
	}
	elseif($perc!=0){

		if($perc<50)
			$im_png=@imagecreatefrompng("images/green.png");
			$im=@imagecreatetruecolor($perc,15);
			@imagecopyresampled($im,$im_png,0,0,0,0,$perc,15,100,15);
			$textcolor=@imagecolorallocate($im,0xff,0xff,0xff);
		if($perc>=50 and $perc<80)
			$im_png=@imagecreatefrompng("images/yellow.png");
			$im=@imagecreatetruecolor($perc,15);
			@imagecopyresampled($im,$im_png,0,0,0,0,$perc,15,100,15);
			$textcolor=@imagecolorallocate($im,0x77,0x77,0x77);
		if($perc>=80) {
			$im_png=@imagecreatefrompng("images/red.png");
			$im=@imagecreatetruecolor($perc,15);
			@imagecopyresampled($im,$im_png,0,0,0,0,$perc,15,100,15);
			$textcolor=@imagecolorallocate($im,0xFF,0xFF,0xFF);
		}


		if($perc>20) {
			@imagettftext($im,$fsize,0,($perc/3),12,$textcolor,"$fface","$perc%");
		}
		@imagepng($im,"images/cache/".$user."_usage.png");
		@imagedestroy($im);

		$size=(100-$perc);

		$im_png=@imagecreatefrompng("images/white.png");
		$im=@imagecreatetruecolor($size,15);
		@imagecopyresampled($im,$im_png,0,0,0,0,$size,15,100,15);
		$textcolor=@imagecolorallocate($im,0x77,0x77,0x77);
	
		if($perc<20) {
			@imagettftext($im,$fsize,0,($size/2),12,$textcolor,"$fface","$perc%");
		}
		@imagepng($im,"images/cache/".$user."_avaliable.png");
		@imagedestroy($im);
		return 0;
	}
	else {
		$im_png=@imagecreatefrompng("images/white.png");
		$im=@imagecreatetruecolor(100,15);
		@imagecopyresampled($im,$im_png,0,0,0,0,100,15,100,15);
		$textcolor=@imagecolorallocate($im,0x77,0x77,0x77);
		@imagettftext($im,$fsize,0,(100/2),12,$textcolor,"$fface","$perc%");
		@imagepng($im,"images/cache/".$user."_avaliable.png");
		@imagedestroy($im);
		return 0;

	}

}

?>
