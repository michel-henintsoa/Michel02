<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Suppression</title>
</head>
<body>
    <?php
        session_start();
        $line=$_GET["line"];
        for($i=0; $i<$_SESSION["b"]; $i++){
            if($i==$line){
                unset($_SESSION["tab"][$i]);
            }
        }
        header("Location: calculsession.php?a=".$_SESSION["a"]."&b=".$_SESSION["b"]);
        exit;
    ?>
</body>
</html>