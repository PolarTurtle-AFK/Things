#f-strings

#format %

curso = "python"
print("tutoriales de % s"%curso)

nombre = "victor"
edad = 25
print("hola soy, % s y tengo % s años" %(nombre, edad))
print("que tal soy {} y mi edad es {} años".format(nombre,edad))

print(f"hola soy {nombre} y mi edad es {edad} años")

#f-strings

class Estudiante:
    def __init__(self,nombre,apellido,edad):
        self.nombre = nombre
        self.apellido = apellido
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}{self.apellido}{self.edad}"

nuevo_estudianate = Estudiante("victor","cruz","25") 
 
print(f"{nuevo_estudianate !r}") 