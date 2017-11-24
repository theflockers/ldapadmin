<?

require_once 'DB.php';

Class AdminDB
{

	function add_userinfo($dsn,$info) /* array info */{

		$options = array(
		'debug'       => 2,
			'portability' => DB_PORTABILITY_ALL,
		);

		$db =& DB::connect($dsn, $options);
		if (PEAR::isError($db)) {
		    die($db->getMessage());
		}
	

		$ret = $db->query("SELECT max(user_id)+1 FROM users"); 
		$user_id = $ret->fetchRow();

		$ret=$db->query("INSERT INTO users
			  (user_id,username,mail_host,alias,created,last_login,language,preferences)
		          VALUES (".$user_id[0].",'".$info['cn']."@".$info['associatedDomain']."','".$info['mailHost']."','".$info['mailHost']."','".date("Y-m-d H:i:s")."','".date("Y-m-d H:i:s")."','pt_BR',' ')");

			if (PEAR::isError($db)) {
				    die($db->getMessage());
				}

		$db->query("INSERT INTO identities (user_id,del,standard,name,organization,email,\"reply-to\",bcc,signature) VALUES (".$user_id[0].",0,1,'".$info['sn']."',' ','".$info['cn']."@".$info['associatedDomain']."','".$info['cn']."@".$info['associatedDomain']."',' ','Sem mais,\n\n".$info['sn']."')");

			if (PEAR::isError($db)) {
			    die($db->getMessage());
			}

	}
/*

CREATE TABLE users (
  user_id integer NOT NULL PRIMARY KEY,
  username varchar(128) NOT NULL default '',
  mail_host varchar(128) NOT NULL default '',
  alias varchar(128) NOT NULL default '',
  created datetime NOT NULL default '0000-00-00 00:00:00',
*/

}

?>
