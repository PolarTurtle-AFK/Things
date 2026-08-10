#clase y estatico
import math
class Pastel:
    def __init__(self,ingredientes):
        self.ingredientes = ingredientes

    def __repr__(self):
        return f'pastel({self.ingredientes !r})'

    @classmethod
    def Pastel_chocolate(cls):
        return cls(['chocolate', 'harina', 'leche'])

    @classmethod
    def Pastel_vainilla(cls):
        return cls(['vainilla', 'harina', 'leche'])
 
print(Pastel.Pastel_chocolate())

#clase y estatico
class Pastel:
    def __init__(self, ingredientes , tamaño):
        self.ingredientes = self.ingredientes
        self.tamaño = tamaño
    def __repr__(self):
        return (f'Pastel({self.ingredientes}, 'f'{self.tamaño})')
    def area(self):
        return self.tamaño_area(self.tamaño)

    @staticmethod

    def tamaño_area(A):
        return A**2*math.pi

nuevo_pastel = Pastel(['harina', 'azucar','leche','crema'],4)
print(nuevo_pastel.tamaño_area(nuevo_pastel.tamaño))
    
