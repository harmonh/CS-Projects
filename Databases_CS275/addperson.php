<?php
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

if($_POST['add'] === 'Add Character') {

	if(!$result = mysqli_query($mysqli, "SELECT fname, lname FROM people 
		WHERE fname = '$fname' AND lname = '$lname'")){
			echo "Query failed: " . $result->errno . " " . $result->error;
		}

	if(mysqli_num_rows($result) === 0) {

		if(!$stmt = $mysqli->prepare("INSERT INTO people(fname, lname, hid, pl_of_birth, rid) VALUES (?,?,?,?,?)")) {
			echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
		}

		if(!$stmt->bind_param("ssiii", $_POST['FirstName'], $_POST['LastName'], $_POST['House'], $_POST['plBirth'], $_POST['Religion'])) {
			echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
		}

		if(!$stmt->execute()) {
			echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
		} else {
			echo "Added " . $stmt->affected_rows . " character to database.";
		}
	}

	else {
		echo "<p>Character is already in database.</p>\n";
	}
}

else {
	if(!$result = mysqli_query($mysqli, "SELECT fname, lname FROM people 
	WHERE fname = '$fname' AND lname = '$lname'")){
		echo "Query failed: " . $result->errno . " " . $result->error;
	}

	if(mysqli_num_rows($result) === 0) {
		echo "Character is not in database.";
	}
	else {
		if(!$update = mysqli_query($mysqli, "UPDATE people SET hid = '$house', pl_of_birth = '$birth', rid = '$rel' WHERE fname = '$fname' AND lname = '$lname'")) {
			echo "Update query failed: " . $update->errno . " " . $update->error;
		}
		else {
			echo $fname . " " . $lname . " was updated.";
		}
	}
}

?>

<p><a href='got_database.php'>Home Page</a></p>

	</table>
</div>

</body>
</html>