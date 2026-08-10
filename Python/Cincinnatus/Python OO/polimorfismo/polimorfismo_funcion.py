class Tomate:
    def tipo(self):
        print("vegetal")
    def color(self):
        print("rojo")
class Manzana:
    def tipo(self):
        print("fruta")
    def color(self):
        print("rojo")

def funcion(objeto):
    objeto.tipo()
    objeto.color()
nuevo_tomate = Tomate()
funcion(nuevo_tomate)
 
nueva_manzana = Manzana()
funcion(nueva_manzana)