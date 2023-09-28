<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "proyecto";

$conexion = new mysqli($servername,$username,$password,$database);

if (!$conexion) {
  die("No se pudo conectar: " .mysqli_connect_error());
}
else{
  
}

?>
