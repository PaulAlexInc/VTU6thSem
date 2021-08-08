<?php
    echo "<h3>Thangam Paul Alex - 1CR18CS172</h3>";
    $a = array(array(1,2,3),array(4,5,6),array(7,8,9));
    $b = array(array(1,2,3),array(4,5,6),array(7,8,9));

    $m = count($a);// no of rows
    $n = count($a[1]);// no of columns
    $p = count($b);// no of rows
    $q = count($b[1]);// no of columns
    echo "MATRIX A IS: <br>";
    for($i=0;$i<$m;$i++)
    {
        for($j=0;$j<$n;$j++)
        {
            echo " ".$a[$i][$j];
        }
        echo "<br>";
    }
    echo "MATRIX B IS: <br>";
    for($i=0;$i<$p;$i++)
    {
        for($j=0;$j<$q;$j++)
        {
            echo " ".$b[$i][$j];
        }
        echo "<br>";
    }
    echo "The transpose of matrix A is: <br>";
    for($i=0;$i<$m;$i++)
    {
        for($j=0;$j<$n;$j++)
        {
            echo " ".$a[$j][$i];
        }
        echo "<br>";
    }
    echo "Addition of two matrices <br>";
    if($m == $p && $n == $q)
    {
        for($i=0;$i<$m;$i++)//start with row of first matrix and end with column of second matrix
        {
        for($j=0;$j<$q;$j++)
        {
            echo $a[$i][$j]+$b[$i][$j]." ";
        }
        echo "<br>";
        }
    }
    echo "Multiplication of two matrices <br>";
    if($n==$p)
    {
        $result = array();
        for($i=0;$i<$m;$i++)
        {
            for($j=0;$j<$q;$j++)
            {
                $result[$i][$j]=0;
                for ($k=0;$k<$n;$k++)
                {
                    $result[$i][$j]+=$a[$i][$k]*$b[$k][$j];
                }
            }
        }
    }
    for($i=0;$i<$m;$i++)
    {
        for($j=0;$j<$q;$j++)
        {
            echo " ".$result[$i][$j];
        }
        echo "<br>";
    }
?>
