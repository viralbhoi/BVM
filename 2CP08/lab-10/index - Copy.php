<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>From fetching</title>
</head>
<body>
    <h1> Submit username and password</h1>

    <form action="welcome.php" method="post">
        username: <input type="text" name="uname" placeholder="username"><br><br>
        password: <input type="password" name="pwd" placeholder="password"><br><br>
        <input type="radio" name="Gender" value="Male"> Male &nbsp; &nbsp;
        <input type="radio" name="Gender" value="female"> Female &nbsp; &nbsp;<br><br>
        Email: <input type="email" name="email"> <br><br>
        Number; <input type="tel" name="Number" > <br><br>
        <button type="submit">Submit details</button><br><br>
    </form>

    <form action="string.php" method="post">
        <button type="submit">Go to string</button><br><br><br>
    </form>

    <form action="func.php" method="post">
        <input type="number" name="N" placeholder="enter N"><br>
        <button type="submit">Find Factorial</button><br>
    </form>
</body>
</html>