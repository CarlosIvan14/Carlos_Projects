<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

include('conexion.php');

// Verificar si se ha enviado el formulario
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Obtener los valores del formulario
    $nombre = $_POST['nombre'];
    $salon = $_POST["salon"];
    $numPersonas = $_POST['num_personas'];
    $cantidadMesas = $_POST['cantidad_mesas'];
    $equipo = $_POST['equipo'];
    $cantidad_equipo=$_POST['cantidad'];
 
    $nuevo_cantidad = array();
    for ($i=0;$i<count($cantidad_equipo);$i++){
    if(empty($cantidad_equipo[$i])){
    }else{
        array_push($nuevo_cantidad, $cantidad_equipo[$i]);
    }
    }
    $cantidad_de_equipos = count($nuevo_cantidad);
    echo var_dump($nuevo_cantidad);
    echo "<br>";
    echo var_dump($equipo);
    // Realizar las operaciones deseadas con los datos recibidos

    // Imprimir los valores utilizando var_dump()
    echo "Nombre: " . $nombre . "<br>";
    echo "Número de personas: " . $numPersonas . "<br>";
    echo "Cantidad de mesas: " .$cantidadMesas. "<br>";
    echo "Equipo : ".$equipo[0]. "<br>";
    echo "Equipo cantidad : ".$nuevo_cantidad[0]. "<br>";

if(empty($_POST['equipo'])){
    header('location:salones.php');
}
$equipo=$_POST['equipo'];
$nuevo_cantidad=$_POST['cantidad'];
if(!empty($_POST['equipo']) && !empty($_POST['cantidad'])  && !empty($_POST['num_personas'])  && !empty($_POST['nombre']) && !empty($_POST['cantidad_mesas'])){

    $consulta_cantidad_mesas="UPDATE salones SET Mesas_Disponibles=Mesas_Disponibles-$cantidadMesas WHERE ID =$salon";
    mysqli_query($conexion,$consulta_cantidad_mesas);
    echo $consulta_cantidad_mesas;

    $consulta_usuarios = "INSERT INTO usuarios (Nombre, numPersonas, numMesas, numEquipo)VALUES ('$nombre', $numPersonas, $cantidadMesas, $cantidad_de_equipos)";
    echo $consulta_usuarios;
    mysqli_query($conexion,$consulta_usuarios);


    for($i=0;$i<count($equipo);$i++){
        echo "<p>Valor recibido: $equipo[$i]</p>";
        $equipo[$i] = (int)$equipo[$i];
        $nuevo_cantidad[$i] = (int)$nuevo_cantidad[$i];
        $consulta="UPDATE equipos SET Cantidad = Cantidad - $nuevo_cantidad[$i]  WHERE ID  = $equipo[$i]";
        mysqli_query($conexion, $consulta);
        $nuevo_cantidad_equipos="SELECT Cantidad FROM equipos WHERE ID = $equipo[$i]";
        $consulta_cantidad_materiales=mysqli_query($conexion, $nuevo_cantidad_equipos);
        $row_equipo=mysqli_fetch_assoc($consulta_cantidad_materiales);
        if($row_equipo['Cantidad']==0){
            $actualiza_cantidad_equipo="UPDATE equipos SET Disponibilidad = 0 WHERE ID = $equipo[$i]";
            mysqli_query($conexion, $actualiza_cantidad_equipo);
        }
    }
    header('location:principal.php');
}else{
    header('location:salones.php');
}  

}
?>
