const http = require('http');
const cursos = require('./cursos');
const { type } = require('os');

const servidor = http.createServer((req,res) =>{
    const {method} = req;

    switch(method){
        case 'GET':
            return manejarSolicitudGET(req,res);
        case 'POST':
            return manejarSolicitudPOST(req,res);
        default:
            res.statusCode = 501;
            console.log(`el metodo usado no puede ser manejado por el server: ${method}`)
    }
})

function manejarSolicitudGET(req,res){
    const path = req.url;
    if (path === '/'){
        return res.end('Bienvenidos a bla bla api con node\nhttp://localhost:3000/cursos\nhttp://localhost:3000/cursos/programacion\nhttp://localhost:3000/cursos/matematicas\n')
    } else if (path === '/cursos'){
        return res.end(JSON.stringify(cursos.infoCursos));
    } else if (path === '/cursos/programacion'){
        return res.end(JSON.stringify(cursos.infoCursos.programacion))
    } else if (path === '/cursos/matematicas'){
        return res.end(JSON.stringify(cursos.infoCursos.matematicas))
    }

    res.statusCode = 404
    res.end('NO EXISTE!!!')
}

function manejarSolicitudPOST(req,res){
    const path = req.url;

    if (path === '/cursos/programacion'){
        
        let cuerpo = '';
        req.on('data', contenido => {
            cuerpo += contenido.toString()
        })

        req.on('end', () => {
            console.log(cuerpo)
            console.log(typeof cuerpo)
            return res.end('RECIBIO SOLICITUD PA /CURSOS/PROGRAMACION')

        })
        // return res.end('RECIBIO SOLICITUD PA /CURSOS/PROGRAMACION')
    }
}
const PUERTO = 3000;

servidor.listen(PUERTO, () =>{
    console.log(`el servidor esta escuchando en el puerto: ${PUERTO}`)
})
//5:55:15