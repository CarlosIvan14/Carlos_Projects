<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8"/>
    <link href="https://fonts.googleapis.com/css2?family=Fira+Sans&display=swap" rel="stylesheet">
    <title>Proyecto_servicioBec</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
    <style>
        .custom-image-btn {
            position: relative;
            overflow: hidden;
        }

        .custom-image-btn img {
            display: block;
            width: 100%;
            height: auto;
        }

        .custom-btn {
            width: 100%;
            height: auto;
        }

        .mesa-btn {
            margin-bottom: 10px;
        }

        .modal-body {
            text-align: center;
        }

        .p {
            color: white;
            font-family: 'Fira Sans', sans-serif;
            text-align: center;
            background-color: rgb(254, 149, 11);
        }
    </style>
</head>
<body>
<?php
include "conexion.php";
?>
<div class="container-fluid">
    <div class="row p">
        <div class="col-1">
            <button class="btn btn-secondary contenedor" onclick="redirectToPrincipal()">Regresar</button>
        </div>
        <div class="col-11">
            <h3 class="text-center p">Elige el laboratorio que deseas reservar:</h1>
        </div>
    </div>
    <div class="row">
        <?php
        $peticion_salones = "SELECT * FROM salones WHERE Mesas_Disponibles > 0";
        $resultado_salones = mysqli_query($conexion, $peticion_salones);
        $equipos_nodisponibles = "UPDATE equipos SET Disponibilidad = 1 WHERE Disponibilidad = 0 AND Cantidad > 0";
        $consulta_equipos_nodisponibles = mysqli_query($conexion, $equipos_nodisponibles);
        while ($salon = mysqli_fetch_assoc($resultado_salones)) {
            ?>
            <div class="col-2">
                <button class="btn btn-primary custom-btn custom-image-btn" id="salon_<?php echo $salon['ID']; ?>" type="button" data-bs-toggle="modal" data-bs-target="#exampleModal_<?php echo $salon['ID']; ?>">
                    <img src="images/vista1.jpg" alt="Imagen del botón">
                    <?php echo $salon['ID']; ?>
                </button>
            </div>
            <?php
            include "modal_registro.php";
        }
        ?>
           <?php
    if (mysqli_num_rows($resultado_salones) == 0) {
        echo "<h4>No hay salones disponibles por el momento</h4>";
    }
    ?>
    </div>
</div>
<script src="script.js"></script>
<script type="text/javascript">
    function redirectToPrincipal() {
            window.location.href = "principal.php";
        }
    function toggleSelection(button) {
        button.classList.toggle('btn-primary');
        button.classList.toggle('btn-secondary');

   
        var modal = button.closest('.modal');

   
        var buttons = modal.getElementsByClassName('mesa-btn');


        var selectedCount = 0;

        for (var i = 0; i < buttons.length; i++) {
            if (buttons[i].classList.contains('btn-secondary')) {
                selectedCount++;
            }
        }

    
        console.log('Botones seleccionados: ' + selectedCount);


        var hiddenInput = modal.querySelector('input[name="cantidad_mesas"]');
        hiddenInput.value = selectedCount;
}

    
    </script>
<script src="js/bootstrap.bundle.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.min.js" integrity="sha512-894YE6QWD5I59HgZOGReFYm4dnWc1Qt5NtvYSaNcOP+u1T9qYdvdihz0PPSiiqn/+/3e7Jo4EaG7TubfWGUrMQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
</html>