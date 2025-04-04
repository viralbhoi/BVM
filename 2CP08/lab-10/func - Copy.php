<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        function fct ($n){
            if($n==0){
                return 1;
            }

            return $n * fct($n - 1);
        }
    ?>

    <?php 

        $fact = fct($_POST["N"]);

        echo "fact of ".$_POST["N"]." is : ".$fact."<br>";
    ?>
</body>
</html>