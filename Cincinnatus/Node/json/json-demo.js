const curso = require('./curso.json');

console.log(typeof curso);

let infoCurso = {
  "titulo": "Aprende Node.js",
  "numVistas": 45642,
  "numLikes": 2142,
  "temas": [
    "Javascript",
    "Node.js"
  ],
  "esPublico": true
}

let infoCursoJSON = JSON.stringify(infoCurso);

console.log(infoCurso);
console.log(typeof infoCurso);
console.log(infoCursoJSON.titulo);

let infoCursoObjeto = JSON.parse(infoCursoJSON);

console.log(infoCursoObjeto);
console.log(typeof infoCursoObjeto);
console.log(infoCursoObjeto.titulo);

//2:43:15