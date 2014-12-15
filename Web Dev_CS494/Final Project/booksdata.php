<?php	
	ini_set('display_errors', 'On');
	if(!session_start())
		echo 'Session failed';

	if(empty($_SESSION['name'])) {
		header('Location: http://web.engr.oregonstate.edu/~harmonh/finalhome.php');
	}

?>


<!DOCTYPE HTML>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <title>Your Book List</title>
  <link rel="stylesheet" href="finalCSS.css"/>
  <script src="jquery-1.11.0.min.js"></script>
  <script src="jquery.validate.js"></script>
  <script src="additional-methods.js"></script>
</head>
 	
<body>
	<div id='header'>
		<img src="pics/open book.jpg" alt="Books">
		<h1>Your Book Database</h1>
	</div>
	<div id='subhead'>
		<a href="http://web.engr.oregonstate.edu/~harmonh/logout.php">Log Out</a>
	</div>
	<div id="main">
	<div id='pageHead'>
		<h3>Books You Have Read</h3>
	</div>
	<div id='logform'>
	<form name="valueinput" method="POST" action="addbook.php">
      Title: 
      <input type="text" name="newtitle" value="" required><BR>
      Author: 
      <input type="text" name="newauth" value="" required><BR><BR>
      <input class='logbutton' type="submit" value="Add Book">
    </form>
	</div>

<?php
	
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "harmonh-db", "p20R6xHuMLLPWi1p", "harmonh-db");
	if ($mysqli->connect_errno) {
   	echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}

	$name = $_SESSION['name'];

	$query = "SELECT title, author FROM book_data WHERE user='".$name."'";
	$table = mysqli_query($mysqli, $query);

	echo '
		<BR><table>
			<tr>
    		<th>Book Title</th>
    		<th>Author</th>';
	$i = 0;
	while($row = mysqli_fetch_array($table, MYSQLI_ASSOC)) {
		$i++;
		echo '
			<tr>
			<td>',$row["title"],'</td>
			<td>',$row["author"],'</td>';
	}
	echo '
		</tr>
		</table><BR>';
?>

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