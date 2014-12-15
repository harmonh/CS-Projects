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
	<BR>
	<h3>Characters: </h3>
<div>
	<table>
		<tr>
			<th>First Name</th>
			<th>Last Name</th>
			<th>House</th>
			<th>Place of Birth</th>
			<th>Religion</th>
		</tr>
<?php
	if(!($stmt = $mysqli->prepare("SELECT people.fname, people.lname, house.name, location.name, religion.name FROM people INNER JOIN 
		house ON people.hid = house.id INNER JOIN
		location ON people.pl_of_birth = location.id INNER JOIN
		religion ON people.rid = religion.id ORDER BY people.lname"))) {
		echo "Prepare failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->execute()) {
		echo "Execute failed: " . $stmt->errno . " " . $stmt->error;
	}
	if(!$stmt->bind_result($fname, $lname, $house, $birth, $religion)) {
		echo "Bind failed: " . $stmt->errno . " " . $stmt->error;
	}
	while ($stmt->fetch()) {
		echo "<tr>\n<td>". $fname . "</td>\n<td>" . $lname . "</td>\n<td>" . $house . "</td>\n<td>" . $birth . "</td>\n<td>" . $religion . "</td>\n</tr>\n";
	}
	$stmt->close();
?>

	</table>
</div>



<BR>
<div>
	<form method="post" action="addperson.php">
		<fieldset>
			<legend> Character </legend>
			<p>First Name: <input type='text' name='FirstName' /></p>
			<p>Last Name: <input type='text' name='LastName' /></p>
			<p>House: 
			<select name="House">
				<option value='12'>None</option>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM house WHERE id <> 12 ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $house)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $house . '</option>\n';
}

$stmt->close();
?>

			</select></p>
			<p>Place of Birth: <select name='plBirth'>
				<option value='14'>None</option>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM location WHERE id <> 14 ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $birth)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $birth . '</option>\n';
}

$stmt->close();
?>
			</select></p>

			<p>Religion: 
			<select name="Religion">
				<option value='6'>None</option>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM religion WHERE id <> 6 ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $religion)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $religion . '</option>\n';
}

$stmt->close();
?>
			</select></p>
		<p><input type='submit' name='add' value='Add Character' /></p>
		<p><input type='submit' name='add' value='Update Character' /></p>
		</fieldset>
	</form>
</div>


<div>
	<form method="post" action="addrelation.php">
		<fieldset>
			<legend> Add Relationship </legend>
			<p><select name='Person'>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, fname, lname FROM people ORDER BY fname"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $fname, $lname)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $fname . " " . $lname . '</option>\n';
}

$stmt->close();
?>
			</select>
			 is the 
			<select name='RelType'>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, type FROM relation_type"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $type)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $type . '</option>\n';
}

$stmt->close();
?>
			</select>
			 of 
			<select name='Relation'>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, fname, lname FROM people ORDER BY fname"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $fname, $lname)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $fname . " " . $lname . '</option>\n';
}

$stmt->close();
?>
			</select></p>

			<p><input type='submit' name='addHo' value='Add Relationship' /></p>
		</fieldset>
	</form>
</div>



<div>
	<form method="post" action="addhouse.php">
		<fieldset>
			<legend> Add New House </legend>
			<p>Name: <input type='text' name='HouseName' /></p>
			<p>Symbol: <input type='text' name='HouseSym' /></p>
			<p>House Words: <input type='text' name='HouseWords' /></p>
			</select></p>
			<p>Location: <select name='HouseLoc'>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM location ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $birth)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $birth . '</option>\n';
}

$stmt->close();
?>
			</select></p>
			<p><input type='submit' name='addHo' value='Add House' /></p>
		</fieldset>
	</form>
</div>







<div>
	<form method="post" action="addloc.php">
		<fieldset>
			<legend> Add New Location </legend>
			<p>Name: <input type='text' name='LocName' /></p>
			<p>Region: <input type='text' name='LocRegion' /></p>
			<p>Language: <select name='LocLang' />
				<option value='Common Tongue'>Common Tongue</option>
				<option value='Dothraki'>Dothraki</option>
				<option value='High Valyrian'>High Valyrian</option>
				<option value='Low Valyrian'>Low Valyrian</option>
				<option value='Lhazareen'>Lhazareen</option>
				<option value='Summer Tongue'>Summer Tongue</option>
				<option value='Language of Asshai'>Language of Asshai</option>
			</select></p>
		<p><input type='submit' name='addLoc' value='Add Location' /></p>
		</fieldset>
	</form>
</div>

<div>
	<form method="post" action="deleteperson.php">
		<fieldset>
			<legend> Remove Character </legend>
			<p><select name='remChar'>
<?php
if(!($stmt = $mysqli->prepare("SELECT id, fname, lname FROM people ORDER BY fname"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $fname, $lname)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $fname . " " . $lname . '</option>\n';
}

$stmt->close();
?>
			</select></p>
		<p><input type='submit' name='delete' value='Remove Character' /></p>
		</fieldset>
	</form>
</div>







<div>
	<fieldset>
		<legend> More Information </legend>
	<form method="post" action="displayhouse.php">		
			<p>House: 
			<select name="House">
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM house ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $house)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $house . '</option>\n';
}

$stmt->close();
?>
		<p><input type='submit' name='house' value='View House' /></p>
	</form>

	<form method="post" action="displayloc.php">		
		<p>Location: 
		<select name="Location">
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM location ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $location)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $location . '</option>\n';
}

$stmt->close();
?>
		<p><input type='submit' name='house' value='View Location' /></p>
	</form>

	<form method="post" action="displayrel.php">		
		<p>Religion: 
		<select name="Religion">
<?php
if(!($stmt = $mysqli->prepare("SELECT id, name FROM religion ORDER BY name"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $religion)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $religion . '</option>\n';
}

$stmt->close();
?>
		<p><input type='submit' name='religion' value='View Religion' /></p>
	</form>

	<form method="post" action="relations.php">		
		<p>Show characters related to: 
		<select name="Relations">
<?php
if(!($stmt = $mysqli->prepare("SELECT id, fname, lname FROM people ORDER BY fname"))){
	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->execute()){
	echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

if(!$stmt->bind_result($id, $fname, $lname)){
	echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

while($stmt->fetch()){
	echo '<option value=" '. $id . ' "> ' . $fname . " " . $lname . '</option>\n';
}

$stmt->close();
?>
		<p><input type='submit' name='relation' value='View Relationships' /></p>
	</form>

	</fieldset>


</div>



</body>
</html>