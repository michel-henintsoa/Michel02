<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="style.css">
    <title>Document</title>
</head>
<body>
    <form action="calcul.php" method="get" class="cent">
    <?php
        $a=$_GET["a"];
        $b=$_GET["b"];
        $edit=$_GET["edit"];
        $line=$_GET["line"];
        //echo "linge a modifier ".$line;
        echo "
            <input type='text' name='a' value='$a' hidden>
            <input type='text' name='b' value='$b' hidden>
            <input type='text' name='line' value='$line' hidden>
            <input type='text' name='mod' value='modif' hidden>
            a=<input type='number' name='a1' value='$a'><br>
            b=<input type='number' name='b1' value='$edit'><br>
            ";
    ?>
        <input type="submit" value="Submit">
    </form>
</body>
</html>