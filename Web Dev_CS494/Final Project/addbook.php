<?php
	ini_set('display_errors', 'On');
	if(!session_start())
		echo 'Session failed';

	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "harmonh-db", "p20R6xHuMLLPWi1p", "harmonh-db");
	if ($mysqli->connect_errno) {
   	echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}

	$string1 = $_REQUEST['newtitle'];
	$string2 = $_REQUEST['newauth'];
		
	if (!$mysqli->query("INSERT INTO book_data(user, title, author) VALUES ('$_SESSION[name]', '$string1', '$string2')")) {
  		echo "Multi-INSERT failed: (" . $mysqli->errno . ") " . $mysqli->error;
	}
	header('Location: http://web.engr.oregonstate.edu/~harmonh/booksdata.php')
?>