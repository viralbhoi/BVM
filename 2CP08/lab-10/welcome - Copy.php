<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome</title>
</head>
<body>
    <h1> Welcome: </h1>
        <?php
            if($_SERVER["REQUEST_METHOD"] == "POST"){
                if(strlen($_POST["uname"]) >= 3){
                    echo $_POST["uname"]."<br>";
                }else{
                    echo "Username is invalid <br>";
                }

                if(strlen($_POST["pwd"]) >= 6){
                    echo "your password is : ".$_POST["pwd"]. "<br>";
                }else{
                    echo "Password is invalid <br>";
                }
                echo "your Gender is : ".$_POST["Gender"]. "<br>";
                echo "your email is : ".$_POST["email"]. "<br>";
                if(strlen($_POST["Number"]) == 10){
                    echo "your Number is : ".$_POST["Number"]. "<br>";
                }else{
                    echo "Number is invalid<br>";
                }
            }
        ?>
</body>
</html>