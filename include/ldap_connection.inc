<?


$conn=ldap_connect($config['ldaphost']);
ldap_set_option($conn,LDAP_OPT_PROTOCOL_VERSION,3);
ldap_set_option($conn,LDAP_OPT_SIZELIMIT,65000);

?>
