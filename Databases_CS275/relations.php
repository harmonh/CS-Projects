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
	$person = $_POST['Relations'];

	if(!($stmt = $mysqli->prepare("SELECT fname, lname FROM people WHERE id = '$person'"))) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()) {
		echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_result($fname, $lname)) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	while ($stmt->fetch()) {
		echo "<h3>Characters related to " . $fname . " " . $lname . ":</h3>";
	}
	$stmt->close();

	if(!($stmt = $mysqli->prepare("SELECT people.fname, people.lname, relation_type.type FROM relation_people INNER JOIN 
		people ON people.id = relation_people.relation_id INNER JOIN
		relation_type ON relation_people.type_id = relation_type.id WHERE relation_people.person_id = '$person'"))) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()) {
		echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_result($fname, $lname, $type)) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	while ($stmt->fetch()) {
		echo "<p>". $type . " of " . $fname . " " . $lname . "</p>\n";
	}
	$stmt->close();
?>

<p><a href='got_database.php'>Home Page</a></p>

	</table>
</div>

</body>
</html>