#metodo super()
class Mamifero:
    def __init__(self,nombre):
        print(nombre,'es un animal de sangre caliente')

class Leon(Mamifero):
    def __init__(self):
        print("el leon es un animal de cuatro patas")
        super().__init__('simba')
        #mamifero.__init__(self,'simba)

nuevo_leon = Leon()

