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

$loc = $_POST['LocName'];

if(!$result = mysqli_query($mysqli, "SELECT name FROM location 
	WHERE name = '$loc'")){
		echo "Query failed: " . $result->errno . " " . $result->error;
	}

if(mysqli_num_rows($result) === 0) {

	if(!$stmt = $mysqli->prepare("INSERT INTO location(name, region, language) VALUES (?,?,?)")) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_param("sss", $_POST['LocName'], $_POST['LocRegion'], $_POST['LocLang'])) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()) {
		echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
	} else {
		echo "Added " . $stmt->affected_rows . " location to database.";
	}
}

else {
	echo "<p>Location is already in database.</p>\n";
}

?>

<p><a href='got_database.php'>Home Page</a></p>

	</table>
</div>

</body>
</html>