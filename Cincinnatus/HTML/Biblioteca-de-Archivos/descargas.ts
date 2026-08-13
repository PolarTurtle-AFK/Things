import { archivos } from "./archivos.js";

export function DescargarArchivo(indice: number) {
    let archivo = archivos[indice]
    archivo.descargar()

    let contador = document.getElementById(`descargas-${indice}`);
    if (contador) {
        contador.textContent = `Descargas: ${archivo.descargas}`;
    }
    console.log(`${archivo.nombre}: ${archivo.descargas}`)
}
