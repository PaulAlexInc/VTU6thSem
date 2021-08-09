<!DOCTYPE html>
<html>
<head>
	<title>Selection Sort</title>
<h3>Thangam Paul Alex - 1CR18CS172</h3>
<br>
</head>
<body>
	<?php
		$servername="localhost";
		$username="root";
		$password="";
		$dbname="weblab1";
		$conn=mysqli_connect($servername,$username,$password,$dbname);
		if($conn->connect_error)
			die("Connection Failed: ".$conn->connect_error);
		else
			echo "Connection is successful";
		$sql = "select * from student";
		$result = $conn->query($sql);
		echo "<table 
		border='2'><tr><th>Name</th><th>USN</th><th>Batch</th></tr>";
		$a = [];
		if($result->num_rows>0)
		{
			while ($row=$result->fetch_assoc()) 
			{
				echo "<tr>";
				echo "<td>".$row["name"]."</td>";
				echo "<td>".$row["usn"]."</td>";
				echo "<td>".$row["batch"]."</td></tr>";
				array_push($a,$row["usn"]);
			}
			echo "</table>";
			echo "<br>";
		}
		else
			echo "Table is empty";
		//selection sort
		$n=count($a);
		for($i=0;$i<($n-1);$i++)
		{
			$pos = $i;
			for($j=$i+1;$j<$n;$j++)
			{
				if($a[$pos]>$a[$j])
					$pos = $j;
			}
			if($pos!=$i)
			{
				$temp = $a[$i];
				$a[$i] = $a[$pos];
				$a[$pos] = $temp;
			}
		}
		$b = [];
		$c = [];
		$result=$conn->query($sql);
		if($result->num_rows>0)
		{
			while ($row=$result->fetch_assoc()) 
			{
				for($i=0;$i<$n;$i++)
				{
					if($row["usn"]==$a[$i])
					{
						$b[$i] = $row["name"];
						$c[$i] = $row["batch"];
					}
				}
			}
		}
		echo "<table 
		border='2'><tr><th>Name</th><th>USN</th><th>Batch</th></tr>";
		for($i=0;$i<$n;$i++)
		{
		echo "<tr>";
		echo "<td>".$b[$i]."</td>";
		echo "<td>".$a[$i]."</td>";
		echo "<td>".$c[$i]."</td></tr>";
		}
		echo "</table></body></html>";
		$conn->close();
	?>