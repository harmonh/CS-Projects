<?php
ini_set('display_errors', 'On');
$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "harmonh-db", "p20R6xHuMLLPWi1p", "harmonh-db");
if ($mysqli->connect_errno) {
	echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
}
?>

<!DOCTYPE html PUBLIC>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
		<link rel="stylesheet" type="text/css" href="gotcss.css">
		<title>Game of Thrones Database</title>
	</head>
<body bgcolor="#E6E6FA">
	<center><img src="pics/gothouses_small.jpg" alt="House Sigils"></center>
	<h1><center>Game of Thrones Database</center></h1>

<?php

$per = $_POST['Person'];
$rel = $_POST['Relation'];
$type = $_POST['RelType'];

if(!$result = mysqli_query($mysqli, "SELECT person_id, relation_id, type_id FROM relation_people 
	WHERE person_id = '$per' AND relation_id = '$rel' AND type_id = '$type'")){
		echo "Query failed: " . $result->errno . " " . $result->error;
	}

if(mysqli_num_rows($result) === 0) {

	if(!$stmt = $mysqli->prepare("INSERT INTO relation_people(person_id, relation_id, type_id) VALUES (?,?,?)")) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_param("iii", $per, $rel, $type)) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()){
		echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
	} else {
		echo "Added " . $stmt->affected_rows . " relationship to database.";
	}
}

else {
	echo "<p>Relationship is already in database.</p>\n";
}

?>

<p><a href='got_database.php'>Home Page</a></p>

	</table>
</div>

</body>
</html>