export class Archivo {
    nombre;
    descripcion;
    ruta;
    tipo;
    descargas;
    constructor(nombre, descripcion, ruta, tipo) {
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.tipo = tipo;
        this.ruta = ruta;
        this.descargas = 0;
    }
    descargar() {
        this.descargas++;
    }
}
export const archivos = [
    new Archivo("Asombrao", ":D", "img/asombrao.jpg", "Imagen"),
    new Archivo("Alejandro Liz", "Profesor", "img/Alejandro.webp", "Imagen"),
    new Archivo("Bocchi", "Bocchi the fade", "img/Bocchi.jpg", "Imagen"),
];
