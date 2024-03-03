<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="style.css">
	<title>Document</title>
</head>
<body>
	<?php
		$a=$_GET["a"];
		$b=$_GET["b"];
		$mod=$_GET["mod"];
		$line=$_GET['line'];
		
		echo "<button hidden>1</button>";
		if(isset($line)){
			echo "misy $line";
			if($mod=="modif"){
				$tab=array();
				if($b>=0){
					for($i=1; $i<=$b; $i++){
						$tmp=$i*$a;
						$row=array($a, $i, $tmp);
						$tab[]=$row;
					}
				}
				else{
					for($i=1; $i<=-$b; $i++){
						$tmp=-$i*$a;
						$row=array($a, -$i, $tmp);
						$tab[]=$row;
					}
				}
				$a1=$_GET["a1"];
				$b1=$_GET["b1"];
				echo "<br>modif $a1";
				echo "$a $b";
				echo "<table>
					<tr style='background-color:#aaaab3'>
					<th>a</th>
					<th>b</th>
					<th>result</th>
					<th>action</th>
					</tr>
					<tbody>";
					
				for($i=0; $i<count($tab); $i++){/* 
					$row=array();
					
						for($j=0; $j<3; $j++)$row[]=$tab[j]; */
					$color=($tab[$i][2]%2==0)?"#a3bacc":"#a3ccb3";
					echo "<tr style='background-color:$color;'>";
					if($line!=$i){
						for($j=0; $j<3; $j++){
							echo "<td>".$tab[$i][$j]."</td>";
						}
					}
					else{
						$tmp=$a1*$b1;
						echo "
							<td>$a1</td>
							<td>$b1</td>
							<td>$tmp</td>
							";
					}
					echo "
						<td style='width: 6em;'>
							<a href='modifier.php?a=$a&b=$b&edit=".$tmp."&mod=modif&line=$i'>
								<button class='mdbutton'>Modify</button>
							</a>
							<a href='calcul.php?a=$a&b=&edit=".$tab[$i][2]."&mod=suppr&line=$i'>
								<button class='mdbutton'>Delet</button>
							</a>
							</td>
						</tr>";
				}
				echo "</tbody></table>";
			}
			else{
				//$disp=($mod=="suppr")?"hidden":"";
				$tab=array();
				if($b>=0){
					for($i=1; $i<=$b; $i++){
						
							$tmp=$i*$a;
							$row=array($a, $i, $tmp);
						if($line!=$i){
							$tab[]=$row;
						}
					}
				}
				else{
					for($i=1; $i<=-$b; $i++){
						
							$tmp=-$i*$a;
							$row=array($a, -$i, $tmp);
						if($line!=$i){
							$tab[]=$row;
						}
					}
				}
				echo "
					<table>
					<tr style='background-color:#aaaab3'>
					<th>a</th>
					<th>b</th>
					<th>result</th>
					<th>action</th>
					</tr>
					<tbody>";
				
			for($i=0; $i<count($tab); $i++){/* 
				$row=array();
				for($j=0; $j<3; $j++)$row[]=$tab[j]; */
				$disp=($i==$line)?"hidden":"";
				$color=($tab[$i][2]%2==0)?"#a3bacc":"#a3ccb3";
				echo "<tr style='background-color:$color;'>";
				for($j=0; $j<3; $j++){
					echo "<td>".$tab[$i][$j]."</td>";
				}
				echo "
					<td style='width: 6em;'>
						<a href='modifier.php?a=$a&b=$b&edit=".$tab[$i][2]."&mod=modif&line=$i'>
							<button class='mdbutton'>Modify</button>
						</a>
						<a href='calcul.php?a=$a&b=&edit=".$tab[$i][2]."&mod=suppr&line=$i'>
							<button class='mdbutton'>Delet</button>
						</a>
						</td>
					</tr>";
			}
			echo "</tbody></table>";
			}
		}
		else{
			/* echo "aaa";
			echo "<a href=\"calcul.php?a=$a&b=$b&line=32\">alefa</a>"; */
			echo "$a $b";
			$tab=array();
			if($b>=0){
				for($i=1; $i<=$b; $i++){
					$tmp=$i*$a;
					$row=array($a, $i, $tmp);
					$tab[]=$row;
				}
			}
			else{
				for($i=1; $i<=-$b; $i++){
					$tmp=-$i*$a;
					$row=array($a, -$i, $tmp);
					$tab[]=$row;
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
				
			for($i=0; $i<count($tab); $i++){/* 
				$row=array();
				for($j=0; $j<3; $j++)$row[]=$tab[j]; */
				$color=($tab[$i][2]%2==0)?"#a3bacc":"#a3ccb3";
				echo "<tr style='background-color:$color;'>";
				for($j=0; $j<3; $j++){
					echo "<td>".$tab[$i][$j]."</td>";
				}
				echo "
					<td style='width: 6em;'>
						<a href='modifier.php?a=$a&b=$b&edit=".$tab[$i][2]."&mod=modif&line=$i'>
							<button class='mdbutton'>Modify</button>
						</a>
						<a href='calcul.php?a=$a&b=&edit=".$tab[$i][2]."&mod=suppr&line=$i'>
							<button class='mdbutton'>Delet</button>
						</a>
						</td>
					</tr>";
			}
			echo "</tbody></table>";
		}

	?>
</body>
</html>
