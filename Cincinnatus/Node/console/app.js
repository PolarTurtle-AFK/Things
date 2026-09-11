// const {saludar , saludarHolaMundo} = require("./saludo.js");

// console.log(saludar("yo"));
// console.log(saludarHolaMundo());
console.log("Hola mundo");
console.warn("Preparate mundo");
console.error("Adios mundo");
console.error(new Error("Chao mundo"));


for (let i = 2; i < process.argv.length; i++){
    console.log(process.argv[i]);
}

console.log(process.memoryUsage());
//1:11h