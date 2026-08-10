#propiedades:()
class Empleado:
    def __init__(self, nombre, salario):
        self.__nombre = nombre
        self.__salario = salario
    def getnombre(self):
        return self.__nombre
    def getsalario(self):
        return self.__salario
    def setnombre(self, nombre):
        self.__nombre = nombre
    def setsalario(self,salario):
        self.__salario = salario
    def delnombre(self):
        del self.__nombre
    def delsalario(self):
        del self.__salario

    nombre = property(fget= getnombre,
                      fset= setnombre,
                      fdel= delnombre,
                      doc = "soy la propiedad del 'nombre'")
empleado_uno = Empleado("VICTOR", 3000)
empleado_uno.nombre = "SARA"
print(empleado_uno.nombre, empleado_uno.getsalario())
help(empleado_uno)