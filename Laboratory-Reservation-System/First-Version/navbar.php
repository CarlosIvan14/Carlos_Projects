<nav class="navbar navbar-expand-lg navbar-light">
            <div class="container-fluid">
              <div class="col-2">
                <img src="images/logos.jpg" alt="Tec de Monterrey" width="90%">
              </div>
              <div class="collapse navbar-collapse col-6 text-center" id="navbarNav">
                <ul class="navbar-nav">
                  <li class="nav-item col-4">
                    <a class="text-center l" href="#seccion1">Conocenos</a>
                  </li>
                  <li class="nav-item col-4">
                    <a class="text-center l" href="#seccion2">Laboratorios</a>
                  </li>
                  <li class="nav-item col-4">
                    <a class="text-center l" href="#seccion3">Materiales</a>
                  </li>
                </ul>
                <div class="col-4 d-flex justify-content-end">
                <button class="btn btn-primary contenedor" onclick="redirectToSalones()">Reserva Ya</button>
                </div>
              </div>
            </div>
          </nav>
    <script>
        function redirectToSalones() {
            window.location.href = "salones.php";
        }
    </script>