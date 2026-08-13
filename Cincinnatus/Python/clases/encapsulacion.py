#Encapsulacion

class Cliente:
    def __init__(self):
        self.__codigo = 4321

    def __cuenta(self):
        print("cuenta de procesamiento")

    def getcodigo(self):
        return self.__codigo
 
persona = Cliente()
#objeto.nombreclase__nombre atributo
print(persona._Cliente__codigo)
persona._Cliente__cuenta()