#polimorfismo

# class Auto:
#     rueda = 4
#     def desplazamiento(self):
#         print(f'elauto esta desplazando sobre {Auto.rueda} ruedas')

# class Moto:
#     rueda = 2
#     def desplazamiento(self):
#         print(f'el motor esta desplazando sobre {Auto.rueda} ruedas')
 
class Animales:
    def __init__(self,nombre):
        self.nombre = nombre

    def tipo_animal(self):
        pass

class Leon(Animales):
    def tipo_animal(self):
        print('animal salvaje')

class Perro(Animales):
    def tipo_animal(self):
        print('animal domestico')

nuevo_animal = Leon('SIMBA')
nuevo_animal.tipo_animal

nuevo_animal2 = Perro('REX')
nuevo_animal2.tipo_animal