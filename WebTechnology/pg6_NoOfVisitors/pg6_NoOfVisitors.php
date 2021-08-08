<?php
	echo "<center><h3>Thangam Paul Alex - 1CR18CS172</h3></center>";
    $file = "count.txt";
    $count = 0;
    $count = strval(file_get_contents($file));
    $count = (int)$count;
    file_put_contents($file, $count+1);
    echo "<center style = 'color:navy'><h1>Visitor Count : ".$count."</h1></center>";
?>