<!DOCTYPE html>
<html>
<head>
    <title>Digital Clock </title>
    <meta http-equiv="refresh" content="1">
</head>
<body>
    <?php
    date_default_timezone_set("Asia/Kolkata");
    echo "<center><p style='border:solid 2px indigo'>The time is: ".date("h:i:s A d D")."
    </p></center>";
    ?>
</body>
</html>