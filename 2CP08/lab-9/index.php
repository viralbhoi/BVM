<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>php</title>
</head>
<body>
    <h1> This is a PHP file </h1>

    <?php 
        echo "<h3>This is a echo word</h3>"."<br>";

        //single line

        /* multi
        line comment
        */

        $name = "Viral";
        $age = 19;
        $cgpa = 8.33;
        $isIndian = true;
        $subLearn  =["WT", "Coa", "CN"];

        echo "name : ".$name."<br>";
        var_dump($name);
        echo "<br>";
        echo "age : ".$age."<br>";
        var_dump($age);
        echo "<br>";
        echo "CGPA : ".$cgpa."<br>";
        var_dump($cgpa);
        echo "<br>";
        echo "Indian : ".$isIndian."<br>";
        var_dump($isIndian);
        echo "<br>";


        if($age > 18){
            echo "Eligible For license <br>";
        }else{
            echo "Minor <br>";
        }
    ?>

    <br>
    <br>
    <table>
        <tr>
            <th>Number</th>
            <th> Square </th>
        </tr>
        <?php
            for($i = 1; $i<= 5; $i++){
                echo "<tr><td>". $i ."</td> <td>". $i * $i ."</td> </tr>";
            }
            $i = 6;
            while($i < 9){
                echo "<tr><td>". $i ."</td> <td>". $i * $i ."</td> </tr>";
                $i++;
            }
        ?>
    </table>
    
    <br>
    <br>

    <?php
        var_dump($subLearn);
        echo "<br>";
        foreach ($subLearn as $sub) {
            echo $sub."<br>";
        }
    ?>
</body>
</html>