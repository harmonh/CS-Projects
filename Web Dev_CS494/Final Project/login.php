<?php
	ini_set('display_errors', 'On');
	if(!session_start())
		echo 'Session failed';

	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "harmonh-db", "p20R6xHuMLLPWi1p", "harmonh-db");
	if ($mysqli->connect_errno) {
   		echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}

	$name = $_POST['username'];
	$pass = $_POST['password'];

	$selected = mysqli_select_db($mysqli, "auth_users");
	// if(!$selected) {
	// 	echo 'Cannont select Database';
	// }

	$query = "SELECT count(*) FROM auth_users WHERE
							user = '".$name."' and
							password = '".$pass."'";

	$result = mysqli_query($mysqli, $query);
	if(!$result) {
		echo "Cannot run query";
	}
	$row = mysqli_fetch_row($result);
	$count = $row[0];
	if ($count > 0) {
		$_SESSION['name'] = $_POST['username'];
		$_SESSION['pass'] = $_POST['password'];
		header("Location: http://web.engr.oregonstate.edu/~harmonh/booksdata.php");
	}
	else {
		echo '<p>Log In failed. <a href="http://web.engr.oregonstate.edu/~harmonh/finalhome.php">Try again</a> or <a href="http://web.engr.oregonstate.edu/~harmonh/account.php">Create Account.</a></p>';
	}
?>