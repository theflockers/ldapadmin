<?
$config['ldaphost']="localhost";
$config['ldapdn']="ou=Mail,o=lmendes";
$config['ldapbinddn']="cn=admin";
$config['ldapbindpw']="your fucking pass";

/* LDAP Add Options */

$config['mailhome'] = "/mail/accounts/";
$config['defaultUID'] = 200;
$config['defaultUID'] = 200;
$config['mailHost'] = "localhost";
$config['mailQuota'] = 2000000;
$config['defaultStatus'] = "active";

$config['dsn']="sqlite://./roundcube.sqlite?mode=0640";


?>
