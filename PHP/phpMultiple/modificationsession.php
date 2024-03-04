<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    aaa
    <?php
    
        session_start();
        $line=$_GET["line"];
        $a1=$_GET["a1"];
        $b1=$_GET["b1"];
        /* if(empty($_SESSION["tab"])){
            for($i=0; i<$_SESSION["b"]; $i++){
                $tmp=$_SESSION["a"]*($i+1);
                $row=array($_SESSION["a"], $i, $tmp);
                $_SESSION["tab"][]=$row;
            }
        } */
        if(!isset($a1) && !isset($b1)){
            echo "<form method=\"get\" action=\"modificationsession.php\">";
            echo "
                a<input type='number' name=a1 placeholder=\"".$_SESSION["a"]."\"><br>
                b<input type='number' name=b1 placeholder=\"".$_SESSION["b"]."\"><br>
                <input type='number' name=line value=$line hidden><br>
                <input type='submit' value='Submit'>
            ";
        }
        else{
            echo "aaaaaaaabbbbBBBBBBaaaaaaaaa";
            for($i=0; $i<$_SESSION["b"]; $i++){
                echo "<br>b";
                if($i==$line){
                    $_SESSION["tab"][$i]=array($a1, $b1, $a1*$b1);
                    echo "\td\t";
                }
                /* else{
                    $_SESSION["tab"][$i]=$_SESSION["tab"][$i];
                    echo "c";
                } */
                echo "nety$line";
            }
            
            echo "<h1>tonga</h1>";
            header("Location: calculsession.php?a=".$_SESSION["a"]."&b=".$_SESSION["b"]);
            exit;
        }
    ?>
</body>
</html>