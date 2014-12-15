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

<div>
	<p><b>Location Info:</b></p>
	<table>
		<tr>
			<th>Name</th>
			<th>Region</th>
			<th>Language</th>
		</tr>
<?php
	$locNum = $_POST['Location'];

	if(!($stmt = $mysqli->prepare("SELECT name, region, language FROM location WHERE id = '$locNum'"))) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()) {
		echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_result($location, $region, $language)) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	while ($stmt->fetch()) {
		echo "<tr>\n<td>". $location . "</td>\n<td>" . $region . "</td>\n<td>" . $language . "</td>\n</tr>\n";
	}
	$stmt->close();
?>

<div>
	<table>
		<tr>
			<th>Characters Born Here</th>
		</tr>
<?php

	if(!($stmt = $mysqli->prepare("SELECT people.fname, people.lname, house.name, location.name, religion.name FROM people INNER JOIN 
		house ON people.hid = house.id INNER JOIN
		location ON people.pl_of_birth = location.id INNER JOIN
		religion ON people.rid = religion.id WHERE location.id = '$locNum'"))) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()) {
		echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_result($fname, $lname, $house, $birth, $religion)) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	while ($stmt->fetch()) {
		echo "<tr>\n<td>". $fname . " " . $lname . "</td>\n</tr>\n";
	}
	$stmt->close();
?>

	</table>
</div>

<p><a href='got_database.php'>Home Page</a></p>

	</table>
</div>

</body>
</html>