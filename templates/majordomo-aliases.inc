<?php

/* Contents of majordomo-aliases */
$content="# ".$ListInfo['domain']."\n";

/* majordomo-domain.com.br */ 
$content.="majordomo-".$ListInfo['domain'].":\t\t\"|/usr/share/majordomo/wrapper majordomo -C  /mail/lists/".$ListInfo['domain']."/config/majordomo.cf\"\n";

/* lista-list-domain.com.br */
$content.=$ListInfo['name']."-list-".$ListInfo['domain'].":\t:include:/mail/lists/".$ListInfo['domain']."/lists/".$ListInfo['name']."\n";

/* lista-domain.com.br */
$content.=$ListInfo['name']."-".$ListInfo['domain'].":\t\t\"|/usr/share/majordomo/wrapper resend -C  /mail/lists/".$ListInfo['domain']."/config/majordomo.cf -l ".$ListInfo['name']." ".$ListInfo['name']."-list-".$ListInfo['domain']." ".$ListInfo['name']."-archive-".$ListInfo['domain']."\"\n";

/* lista-request-domain.com.br */
$content.=$ListInfo['name']."-request-".$ListInfo['domain'].":\t\"|/usr/share/majordomo/wrapper  majordomo -C  /mail/lists/".$ListInfo['domain']."/config/majordomo.cf -l ".$ListInfo['forwarding']."\"\n";

/* lista-archive-domain.com.br */
$content.=$ListInfo['name']."-archive-".$ListInfo['domain'].":\t\"|/usr/share/majordomo/wrapper archive2.pl -f  /mail/lists/".$ListInfo['domain']."/lists/".$ListInfo['name'].".archive/msg -a -M\"\n\n";
?>
