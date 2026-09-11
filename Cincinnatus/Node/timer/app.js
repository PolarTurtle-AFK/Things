function mostrarTema(tema){
    console.log(`estoy aprendiendo ${tema}`);
}

//setTimeout(mostrarTema, 2000, `Node.js`);
// //1:27:52
function sumar(a,b){
    console.log(a+b);
}

setTimeout(sumar,2000,5,6);
setImmediate(mostrarTema, 'Node.js');
setInterval(mostrarTema,1500,`node.js`);