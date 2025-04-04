<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>String</title>
</head>
<body>
    <h1>Working with strings;</h1>

    <?php
        $mystring = "This is a sample string, i am going to perform operations on this";

        echo "string Length is :".strlen($mystring)."<br>";
        echo "Word cout : ".str_word_count($mystring)."<br>";
        echo "to reverse a string we use strrev function : <br>".strrev($mystring)."<br>";

        echo "<h2> Working with substr </h2>";

        $substring = substr($mystring,0,16);
        echo "Sub string is : ".$substring."<br>";

        $new = str_replace("sample","apple",$substring);
        echo "Replacing a substring : ".$new." <br>";

        echo "<h2> Single quotes vs double Quotes</h2>";

        $fruit = "mango";

        echo 'fruit : $fruit <br>';
        echo "fruit : $fruit <br>";
        echo "strtoupper: ".strtoupper($fruit)."<br>";
        echo "strtolower: ".strtolower($fruit)."<br>";


    ?>
</body>
</html>