const express = require('express');
const app = express();

const {infoCursos} = require('./datos/cursos');
//routers

const routerProgramacion = require('./routers/programacion.js');
app.use('/api/cursos/programacion', routerProgramacion);
const routerMatematicas = require('./routers/matematicas.js');
app.use('/api/cursos/matematicas', routerMatematicas);



//routing
app.get('/', (req,res) => {
    res.send('mi primer server. cursos')
})

app.get('/api/cursos', (req,res) => {
    res.send(JSON.stringify(infoCursos));
})

const PUERTO = process.env.PORT || 3000;
app.listen(PUERTO, () =>{console.log("el servidor esta escucando")})