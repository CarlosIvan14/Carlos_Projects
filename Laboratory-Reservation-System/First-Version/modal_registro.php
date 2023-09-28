<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

include "conexion.php";

$equipos_nodisponibles = "UPDATE equipos SET Disponibilidad = 1 WHERE Disponibilidad = 0 AND Cantidad > 0";
$consulta_equipos_nodisponibles = mysqli_query($conexion, $equipos_nodisponibles);
?>

<link href="css/bootstrap.min.css" rel="stylesheet">
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
<link rel="stylesheet" type="text/css" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">

<div class="modal fade" id="exampleModal_<?php echo $salon['ID']; ?>" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="modalLabel_<?php echo $salon['ID']; ?>">Formulario de reserva</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body">
                <form action="Procesa_equipos.php" method="POST" id="form">
                    <div class="mb-3">
                        <label for="nombre" class="form-label">Nombre de la persona que reserva</label>
                        <input type="text" class="form-control" id="nombre" name="nombre" required>
                    </div>
                    <div class="mb-3">
                        <label for="num_personas" class="form-label">Número de personas que van a utilizar el espacio (máximo 7)</label>
                        <input type="number" class="form-control" id="num_personas" name="num_personas" min="1" max="7" required>
                    </div>
                    <div class="row" id="mesas-container">
                        <?php for ($i = 1; $i <= $salon['Mesas_Disponibles']; $i++) { ?>
                            <div class="col-md-6">
                                <button class="btn btn-primary mesa-btn" type="button" onclick="toggleSelection(this)">Mesa <?php echo $i ?></button>
                            </div>
                        <?php } ?>
                    </div>
                    <?php
                    // Establecer la zona horaria
                    date_default_timezone_set("America/Mazatlan");

                    // Obtener la hora actual en formato de 24 horas
                    $hora_actual = date("H:i");

                    // Consulta para obtener las horas disponibles después de la hora actual
                    $consulta = "SELECT Horas FROM horario WHERE STR_TO_DATE(Horas, '%h:%i %p') >= STR_TO_DATE('$hora_actual', '%H:%i')";
                    $resultado = $conexion->query($consulta);

                    // Verificar si hay resultados
                    if ($resultado && $resultado->num_rows > 0) {
                    // Generar el campo de formulario
                    echo '<select name="hora">';
                    echo '<option value="" selected>Selecciona un horario de reserva</option>';
                    
                    // Obtener la primera hora
                    $fila = $resultado->fetch_assoc();
                    $hora_anterior = $fila['Horas'];
                    
                    while ($fila = $resultado->fetch_assoc()) {
                        $hora = $fila['Horas'];
                        echo '<option value="De ' . $hora_anterior . ' a ' . $hora . '">' . 'De ' . $hora_anterior . ' a ' . $hora . '</option>';
                        $hora_anterior = $hora;
                    }
                    
                    echo '</select>';
                    } else {
                    echo 'No hay horarios disponibles para el día de hoy.';
                    }

                    ?>
                    <input type="hidden" id="hiddenInput" name="cantidad_mesas" value="">
                    <input type="hidden" id="salon" name="salon" value="<?php echo $salon['ID']; ?>">
                    <div class="container-fluid row accordion" id="accordionFlushExample">
                        <div class="accordion-item">
                            <h2 class="accordion-header" id="flush-headingOne">
                                <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#flush-collapseOne_<?php echo $salon['ID']; ?>" aria-expanded="false" aria-controls="flush-collapseOne_<?php echo $salon['ID']; ?>" style="background-color: black; color: white; width: 100%;">
                                    Equipo de trabajo
                                </button>
                            </h2>
                            <div id="flush-collapseOne_<?php echo $salon['ID']; ?>" class="accordion-collapse collapse" aria-labelledby="flush-headingOne" data-bs-parent="#accordionFlushExample">
                                <div class="accordion-body">
                                    <form action="" method="POST">
                                        <label class="form-label">Buscar</label>
                                        <input onkeyup="buscar($('#<?php echo $salon['ID']; ?>').val(), <?php echo $salon['ID']; ?>)" type="text" class="form-control" id="<?php echo $salon['ID']; ?>" name="<?php echo $salon['ID']; ?>">
                                    </form>

                                    <p></p>
                                    <table class="table">
                                        <thead>
                                            <th scope ="col">Nombre</th>
                                            <th scope ="col">Marca</th>
                                            <th scope ="col">Modelo</th>
                                            <th scope ="col">Reservar</th>
                                        </thead>

                                        <tbody id="<?php echo $salon['ID'].'c'; ?>">

                                        </tbody>

                                    </table>
                                    <div class="modal-footer">
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancelar</button>
                                        <button type="submit" class="btn btn-primary">Reservar espacio</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </form>    
        </div>
    </div>
</div> 

<script type="text/javascript">
    function buscar(buscar, content){
        var id_string = content.toString();
        var id_definitivo = id_string+'c';
        console.log(id_definitivo);
        console.log(document.getElementById(id_string,'c'));
        console.log(typeof id_string);
        console.log(buscar);
        var parametros = {"buscar": buscar};
        $.ajax({
            data:parametros,
            type: "POST",
            url: 'procesa_reserva_equipos.php',
            success: function (data){
                document.getElementById(id_definitivo).innerHTML= data;
            }
        });
    }
</script>

<script src="js/bootstrap.bundle.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.min.js" integrity="sha512-894YE6QWD5I59HgZOGReFYm4dnWc1Qt5NtvYSaNcOP+u1T9qYdvdihz0PPSiiqn/+/3e7Jo4EaG7TubfWGUrMQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>


 