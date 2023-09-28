<?php
require 'consultas_materiales.php';
?>
<div class="container-fluid" id="seccion3">
    <div class="row contenerdor5">
        <div class="accordion custom-accordion" id="accordionFlushExample">
        <div class="accordion-item">
            <h2 class="accordion-header" id="flush-headingOne">
            <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#flush-collapseOne" aria-expanded="false" aria-controls="flush-collapseOne">
                <h4>Equipo de trabajo</h4>
            </button>
            </h2>
            <div id="flush-collapseOne" class="accordion-collapse collapse" aria-labelledby="flush-headingOne" data-bs-parent="#accordionFlushExample">
            <div class="accordion-body">
                <table class="table">
                <thead>
                    <tr>
                    <th scope="col">Imagen</th>
                    <th scope="col">Nombre</th>
                    <th scope="col">Marca</th>
                    <th scope="col">Modelo</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    $consulta = mysqli_query($conexion, $peticion_equipos_sinrepetir);
                    foreach ($consulta as $equipo) {
                    echo "<tr>";
                    echo "<td>" . "<img src='images/modelo_materiales/" . $equipo['Imagen'] . "' class='img-fluid' alt='Responsive image' height='350px' width='300px'>" . "</td>" . "<td>" . "<h6 style='color: #081969; font-size: 20px;'>" . $equipo['Equipo'] . "</h6>" . "</td>" . "<td>" . "<p>" . "" . $equipo['Marca'] . "</p>" . "</td>" . "<td>" . "<p>" . "" . $equipo['Modelo'] . "</p>" . "</td>";
                    echo "</tr>";
                    }
                    ?>
                </tbody>
                </table>
            </div>
            </div>
        </div>
        </div>
    </div>
</div>

