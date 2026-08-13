import { archivos } from "./archivos.js";
import { DescargarArchivo } from "./descargas.js";
const posts = document.getElementById("posts");
console.log(archivos);
const CantidadArchivos = document.getElementById("CantidadArchivos");
if (CantidadArchivos) {
    CantidadArchivos.textContent = `Archivos disponibles: ${archivos.length}`;
}
if (posts) {
    for (let i = 0; i < archivos.length; i++) {
        let archivo = archivos[i];
        posts.innerHTML += `
            <article class="post">
                <div class="headpost">
                    <h2>${archivo.nombre}</h2>
                    <p>${archivo.descripcion}</p>

                    <img src="${archivo.ruta}" width="400" height="400" class="imagen">

                    <p>Tipo de Archivo: ${archivo.tipo}</p>

                    <a href="${archivo.ruta}" download class="boton" id="btn-${i}">
                        Descargar
                    </a>

                    <p id="descargas-${i}"> Descargas: ${archivo.descargas} </p>
                </div>
            </article>
        `;
    }
}
for (let i = 0; i < archivos.length; i++) {
    const boton = document.getElementById(`btn-${i}`);
    if (boton) {
        boton.addEventListener("click", (e) => {
            DescargarArchivo(i);
        });
    }
}
