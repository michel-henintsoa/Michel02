<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>using Session</title>
    
</head>
<body>
    <?php
        session_start();
        $_SESSION["tab"];
        $_SESSION["a"]=$_GET["a"];
        $_SESSION["b"]=$_GET["b"];
        echo $_SESSION["a"]." ".$_SESSION["b"];
        if(empty($_SESSION["tab"])){
            $_SESSION["tab"];
            for($i=0; $i<$_SESSION["b"]; $i++){
                $tmp=$_SESSION["a"]*($i+1);
                $row=array($_SESSION["a"], $i+1, $tmp);
                $_SESSION["tab"][]=$row;
                echo "a";
            }
        }
        echo "<table>
				<tr style='background-color:#aaaab3'>
                    <th>a</th>
                    <th>b</th>
                    <th>result</th>
                    <th>action</th>
				</tr>
				<tbody>";
                /* echo "<tr hidden>
                        <td>a</td>
                        <td>a</td>
                        <td>a</td>
                        <td>a</td>
                    </tr>
                "; */
        for($i=0; $i<$_SESSION["b"]; $i++){
            $color=($_SESSION["tab"][$i][2]%2==0)?"#a3bacc":"#a3ccb3";
			echo "<tr style='background-color:$color;'>";
			for($j=0; $j<3; $j++){
				echo "<td>".$_SESSION["tab"][$i][$j]."</td>";
			}
            $tmp=$i;
            echo "
            <td style='width: 6em;'>
                <a href='modificationsession.php?line=$tmp'>
                    <button class='mdbutton'>Modify</button>
                </a>
                <a href='suppressionsession.php?line=$tmp'>
                    Delet
                </a>
                </td>
            </tr>
            ";

        }
		echo "</tbody></table>";
    ?>
</body>
</html>