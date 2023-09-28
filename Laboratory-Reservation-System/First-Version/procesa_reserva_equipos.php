<?php
require 'conexion.php';
$busqueda = $_POST["buscar"];
$buscador="SELECT * FROM equipos WHERE Disponibilidad = 1 AND Equipo LIKE ('%".$busqueda."%')";
$resultado = mysqli_query($conexion, $buscador);
$numero = mysqli_num_rows($resultado);

foreach($resultado as $resultadoB){ 
        echo '<tr>';
        echo'<td>'.$resultadoB['Equipo'].'</td>';
        echo '<td>'.$resultadoB['Marca'].'</td>';
        echo '<td>'.$resultadoB['Modelo'].'</td>';
        echo '<td>'."<input type= 'checkbox' name= 'equipo[]' value='".$resultadoB['ID']."'".">"."<input type ='number' name= 'cantidad[]'  min= '1' max= '".$resultadoB['Cantidad']."' step = '1'".">".'</td>';
        echo'<tr>';
    }
?>