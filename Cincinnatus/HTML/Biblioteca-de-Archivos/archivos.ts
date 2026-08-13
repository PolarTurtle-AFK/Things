export class Archivo {
    nombre: string;
    descripcion: string;
    ruta: string;
    tipo: string;
    descargas: number;

    constructor(
        nombre: string,
        descripcion: string,
        ruta: string,
        tipo: string
    ) {
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

export const archivos: Archivo[] = [
    new Archivo("Asombrao", "D:", "img/asombrao.jpg", "Imagen"),
    new Archivo("Alejandro Liz", "Profesor", "img/Alejandro.webp", "Imagen"),
    new Archivo("Bocchi", "Bocchi the fade", "img/Bocchi.jpg", "Imagen"),
];

