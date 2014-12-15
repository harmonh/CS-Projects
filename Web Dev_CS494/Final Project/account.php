<?php
	ini_set('display_errors', 'On');
	if(!session_start())
		echo 'Session failed';

?>

<!DOCTYPE HTML>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <title>Create Account</title>
  <link rel="stylesheet" href="finalCSS.css"/>
  <script src="jquery-1.11.0.min.js"></script>
  <script src="jquery.validate.js"></script>
  <script src="additional-methods.js"></script>
 	
</head>
 	
<body>
	<div id='header'>
		<img src="pics/open%20book.jpg" alt="Books">
		<h1>Your Book Database</h1>
		
	</div>
	<div id='subhead'>
		<a href="http://web.engr.oregonstate.edu/~harmonh/finalhome.php">Log In</a>
	</div>
	<div id="main">
	<div id='pageHead'>
		<h3>Create Account</h3>
	</div>
	<div id='logform'>
		<form class="cmxform" id="account" method="POST">
			Username: (Must be at least 8 characters) 
			<input type="text" value='' id="username" name="username" minlength="8" required>
			<BR>
			Password: (Must be at least 6 characters long)
			<input type='password' value='' id='password' name='password' minlength='6' required>
			<BR>
			<input id="newacc" class='logbutton' type='submit' value='Create Account'>
		</form>

		<script>
			$("#account").validate();
		</script>

	</div>
	<div id='sidebar'>
		<h3>Book Links!</h3>
		<ul>
			<li><a href="http://www.powells.com/">Powell's Books</a></li>
			<li><a href="http://www.multcolib.org/">Multnomah County Library</a></li>
			<li><a href="http://www.newyorker.com/topics/books">The New Yorker Reviews</a></li>
		</ul>
	</div>
</div>

<?php
if(isset($_POST['username'])) {
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "harmonh-db", "p20R6xHuMLLPWi1p", "harmonh-db");
	if ($mysqli->connect_errno) {
  	echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}


	$name = $_POST['username'];
	$pass = $_POST['password'];

	if (!$mysqli->query("INSERT INTO auth_users(user, password) VALUES ('$name', '$pass')")) {
			if($mysqli->errno == 1062) {
				echo '<p>"'.$name.'" is already in use.</p>';
				unset($_POST['username']);
			}
			else{
    			echo "Multi-INSERT failed: (" . $mysqli->errno . ") " . $mysqli->error;
				}
	}
	else {
		echo '<p>Success! <a href="http://web.engr.oregonstate.edu/~harmonh/finalhome.php">Login Here.</a></p>';
	}
}

?>
</body>
</html>