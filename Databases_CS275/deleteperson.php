<?php
ini_set('display_errors', 'On');
$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "harmonh-db", "p20R6xHuMLLPWi1p", "harmonh-db");
if ($mysqli->connect_errno) {
	echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
}

$id = $_POST['remChar'];

if(!$stmt = $mysqli->prepare("DELETE FROM relation_people WHERE person_id = '$id' OR relation_id = '$id'")) {
	echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()) {
	echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->close()) {
	echo "Close failed: " . $stmt->errno . " " . $stmt->error;
}

if(!$stmt = $mysqli->prepare("DELETE FROM people WHERE id = '$id'")) {
	echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()) {
	echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
} else {
	header('Location: http://web.engr.oregonstate.edu/~harmonh/got_database.php');
}

?>