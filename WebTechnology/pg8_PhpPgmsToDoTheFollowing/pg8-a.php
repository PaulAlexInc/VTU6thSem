<!DOCTYPE html>
<html>
<head>
	<title>Calculator</title>
</head>
<body>
	<form action="" method="POST">
	<table border = "3">
		<caption>CALCULATOR</caption>
		<tr>
			<th>Value 1:</th><td><input type="text" name="a"></td>
		</tr>
		<tr>
			<th>Value 2:</th><td><input type="text" name="b"></td>
		</tr>
		<tr>
			<th colspan="2"><input type="submit" name="cal" value="CALCULATE"></th>
		</tr>
	</form>
	
	<?php
	echo "<h3>Thangam Paul Alex - 1CR18CS172</h3>";
	if(isset($_POST['cal']))
	{
		$a = $_POST['a'];
		$b = $_POST['b'];
		if(is_numeric($a) && is_numeric($b))
		{
			echo "<tr><th>ADDITION</th><td>".($a+$b)."</td></tr>";
			echo "<tr><th>SUBTRACTION</th><td>".($a-$b)."</td></tr>";
			echo "<tr><th>MULTIPLICATION</th><td>".($a*$b)."</td></tr>";
			echo "<tr><th>DIVISION</th><td>".($a/$b)."</td></tr>";
		}
		else
			echo "Invalid Input";
	}
	echo "</table>";
?>

</body>
</html>