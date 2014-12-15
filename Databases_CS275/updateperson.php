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

$fname = $_POST['FirstName'];
$lname = $_POST['LastName'];
$house = $_POST['House'];
$birth = $_POST['plBirth'];
$rel = $_POST['Religion'];

if(!$result = mysqli_query($mysqli, "SELECT fname, lname FROM people 
	WHERE fname = '$fname' AND lname = '$lname'")){
		echo "Query failed: " . $result->errno . " " . $result->error;
	}

if(mysqli_num_rows($result) === 0) {
	echo "Character is not in database.";
}
else {
	if(!$update = $mysqli_query($mysqli, "UPDATE people SET hid = '$house', pl_of_birth = '$birth', rid = '$rel' WHERE fname = '$fname' AND lname = '$lname')")) {
		echo "Update query failed: " . $stmt->errno . " " . $stmt->error;
	}
	else {
		echo "Updated " . $stmt->affected_rows . " character.";
	}
}

?>

<p><a href='got_database.php'>Home Page</a></p>

	</table>
</div>

</body>
</html>