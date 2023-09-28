<?php
include('conexion.php');

$nombre=$_POST['nombre'];
$correo=$_POST['correo'];
$password=$_POST['password'];
//Contraseña encriptada
$password = hash('sha256',$password);

$query = "INSERT INTO usuarios (Nombre, Correo, Contrasena) VALUES ('$nombre', '$correo','$password')"; 

echo "<br>";

$verificar_correo = mysqli_query($conexion, "SELECT * FROM usuarios WHERE correo = '$correo'");

if(mysqli_num_rows($verificar_correo)>0){
	echo ' 
	<script>
		alert("Este correo ya esta registrado");
		window.location = "../Proyecto/principal.php";
	</script>
	
	';
}else{

if (mysqli_query($conexion, $query)==True) { 
	header('location:principal.php');
}
}
?>