	include "config/config.php";

        $dsearch=ldap_search($conn,"ou=Domains,".$config['ldapdn'],"(objectClass=dnsDomain)",$attr=array("associatedDomain"));

	$domain=ldap_get_entries($conn,$dsearch);

	for($i=0;$i<count($domain);$i++){

		if($domain[$i]['associateddomain']) {

			echo $domain[$i]['associateddomain'][0]."<br>";

			$usearch=ldap_search($conn,"ou=Domains,".$config['ldapdn'],"(associatedDomain=".$domain[$i]['associateddomain'][0].")",$attr=array("cn"));
			$userobject=ldap_get_entries($conn,$usearch);
			
			for($z=0;$z<count($userobject);$z++) {
				if($userobject[$z]['cn']) {
					echo $userobject[$z]['cn'][0]."<br>";
				}	
			}
			
		}
	}