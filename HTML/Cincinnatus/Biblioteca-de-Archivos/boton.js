let descargas = 0
const DescargasText = document.getElementById("descargas")

function Descargas(){    
    descargas++
    DescargasText.textContent = `Descargas: ${descargas}`
}
