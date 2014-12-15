<?php
	ini_set('display_errors', 'On');
	if(!session_start())
		echo 'Session failed';

	unset($_SESSION['name']);
	unset($_SESSION['pass']);

	if(session_destroy()) {
		header('Location:http://web.engr.oregonstate.edu/~harmonh/finalhome.php');
	}

?>