<?php

/*
dn: cn=suporte,dc=lmendes,dc=com,dc=br,ou=Lists,ou=Mail,o=lmendes
objectClass: top
objectClass: inetMailGroup
objectClass: inetOrgPerson
objectClass: domainRelatedObject
moderator: postmaster@lmendes.info
inetMailGroupVersion: 0
requestsTo: suporte-request@lmendes.info
cn: suporte
sn: suporte
mail: suporte@lmendes.info
mailForwardingAddress: suporte-lmendes.info
associatedDomain: lmendes.info
rfc822mailmember: lmendes@lmendes.info
rfc822mailmember: theflockers@gmail.com
*/

$info['objectClass'][0] = "top";
$info['objectClass'][1] = "inetMailGroup";
$info['objectClass'][2] = "inetOrgPerson";
$info['objectClass'][3] = "domainRelatedObject";
$info['cn'] = $_POST['cn'];
$info['sn'] = $_POST['sn'];
$info['moderator'] = "postmaster@".$_SESSION['domain'];
$info['requeststo'] = $_POST['cn']."-request@".$_SESSION['domain'];
$info['inetMailGroupVersion'] = 0;
$info['mailforwardingAddress'] = $_POST['cn']."-".$_SESSION['domain'];
$info['mail'] = $_POST['mail'];
$info['associatedDomain']= $_SESSION['domain'];

?>
