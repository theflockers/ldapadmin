<?php

$info['objectClass'][0] = "dnsDomain";
$info['objectClass'][1] = "domainRelatedObject";
$info['description'] = $_POST['description'];
$info['dc'] = strtoupper($domain[0]);
$info['associatedDomain'] = $_POST['domain'];
$info['mailQuota'] = ($_POST['mailquota'] * 1024 * 1024);

?>
