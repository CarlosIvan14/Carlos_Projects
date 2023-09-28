<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8"/>
    <link rel="stylesheet" href="styles/estilo.css" type="text/css">
    <link href="https://fonts.googleapis.com/css2?family=Fira+Sans&display=swap" rel="stylesheet">
    <title>Proyecto_servicioBec</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
<link rel="stylesheet" type="text/css" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
</head>
<body> 
  <?php
  #Barra de navegacion
  include 'navbar.php';
  #Carousel de imagenes de la vista del edificio
  include 'carousel.php'; 
  #Seccion descripcion
  include 'descripcion.php'; 
  #Seccion Laboratorios
  include 'laboratorios.php';
  #Seccion materiales
  include 'equipos.php'; 
  #Pie de pagina 
  include 'footer.php'; 
?>
<script src="script.js"></script>
</body>
<script src="js/bootstrap.bundle.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.min.js" integrity="sha512-894YE6QWD5I59HgZOGReFYm4dnWc1Qt5NtvYSaNcOP+u1T9qYdvdihz0PPSiiqn/+/3e7Jo4EaG7TubfWGUrMQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
</html>