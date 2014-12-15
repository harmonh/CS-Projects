<?php
	ini_set('display_errors', 'On');
	if(!session_start())
		echo 'Session failed';
	
?>

<!DOCTYPE HTML>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <title>Login Page</title>
  <link rel="stylesheet" href="finalCSS.css"/>
  <script src="jquery-1.11.0.min.js"></script>
  <script src="jquery.validate.js"></script>
  <script src="additional-methods.js"></script>
</head>
	<body>
	<div id='header'>
		<img src="pics/open%20book.jpg" alt="Books">
		<h1>Book Database</h1>
	</div>
	<div id='subhead'>
	</div>

	<div id="main">
	<div id='pageHead'>
		<h3>Login Page</h3>
	</div>
	<div id='logform'>
		<form method='POST' id='login' action="login.php">
			<p>Username: <input type='text' name='username' required></p>
			<p>Password: <input type='password' name='password' required></p>
			<p><input class='logbutton' type='submit' name='login' value='Log In'></p> 
		</form>
	</div>
	<p><a href="http://web.engr.oregonstate.edu/~harmonh/account.php">Create New Account</a></p>
	</div>
	<div id='sidebar'>
		<h3>Book Links!</h3>
		<ul>
			<li><a href="http://www.powells.com/">Powell's Books</a></li>
			<li><a href="http://www.multcolib.org/">Multnomah County Library</a></li>
			<li><a href="http://www.newyorker.com/topics/books">The New Yorker Reviews</a></li>
		</ul>
	</div>
	</body>
</html>