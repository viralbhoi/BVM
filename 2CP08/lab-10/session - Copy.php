<?php
    session_start();
    $uservisit = 0;
    $_SESSION["user_visit"] = $uservisit;
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>session</title>
</head>
<body>
    <?php
        echo "USER VISITED ". $_SESSION["user_visit"] . "<br>";
        $uservisit++;
    ?>
</body>
</html>