<?php
include "conexion.php";
$peticion_equipos = "SELECT * FROM equipos";
$peticion_equipos_sinrepetir = "SELECT DISTINCT Equipo, Marca ,Modelo, Imagen FROM equipos  ";
$peticion_salones = "SELECT * FROM salones";

?>
    