<?php
    setcookie("user","VIral Bhoi", time() + 3600 * 3, "/");
    $uservisit = 0;
    setcookie("uservisit",$uservisit, time() + 3600 * 3, "/");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        if(!isset($_COOKIE["user"])){
            echo "cookie is not set for user <br>";
        }else{
            echo "cookie is set for". $_COOKIE["user"] ."<br>";
            $uservisit++;
            setcookie("uservisit",$uservisit, time() + 3600 * 3, "/");
        }

        
        

        echo "User visit cout is : ".$_COOKIE["uservisit"]."<br>";
    ?>
</body>
</html>