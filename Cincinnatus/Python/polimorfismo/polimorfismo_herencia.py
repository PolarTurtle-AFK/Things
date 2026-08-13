#polimorfismo con herencia

class Aves:
    def volar(self):
        print("la mayoria de las aveces vuelan")
class Aguila(Aves):
    def volar(self):
        print("las aguilas pueden voar")
class Gallina(Aves):
    def volar(self):
        print("Las gallinas no vuelan")
 
obj_ave = Aves()
obj_ave.volar
obj_aguila = Aguila()
obj_gallina = Gallina()
obj_aguila.volar()
obj_gallina.volar()