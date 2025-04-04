<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Object oriented Programming</title>
</head>
<body>
    <?php
        class Car {
            public $name;
            public $company;

            function __construct($name,$company){
                $this->name = $name;
                $this->company = $company;

                echo "<br><br>Constructor is called <br><br>";
            }

            function get_name() {
              return $this->name;
            }
            function get_company() {
                return $this->company;
            }
        }

        $car1 = new Car('F-type','Jaguar');

        echo "car name : ",$car1->get_name(),"<br>";
        echo "car company : ",$car1->get_company(),"<br>";

        $car2 = new Car('Velar','RangeRover');


        echo "car name : ",$car2->get_name(),"<br>";
        echo "car company : ",$car2->get_company(),"<br>";
    ?>
</body>
</html>