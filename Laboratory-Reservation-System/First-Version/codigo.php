include('conexion.php');
echo $_POST['equipo'];
echo $_POST['equipo'];
if(empty($_POST['equipo'])){
    header('location:salones.php');
}
$equipo=$_POST['equipo'];
$cantidad=$_POST['cantidad'];
if(!empty($_POST['equipo']) && !empty($_POST['cantidad'])){
    for($i=0;$i<=count($equipo)-1;$i++){
        echo "<p>Valor recibido: $equipo[$i]</p>";
        $equipo[$i] = (int)$equipo[$i];
        $cantidad[$i] = (int)$cantidad[$i];
        $consulta="UPDATE equipos SET Cantidad = Cantidad - $cantidad[$i]  WHERE ID  = $equipo[$i]";
        mysqli_query($conexion, $consulta);
        $cantidad_equipos="SELECT Cantidad FROM equipos WHERE ID = $equipo[$i]";
        $consulta_cantidad_materiales=mysqli_query($conexion, $cantidad_equipos);
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