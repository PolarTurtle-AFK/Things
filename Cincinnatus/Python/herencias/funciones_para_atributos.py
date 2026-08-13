#funciones para atributos

class Persona:
    edad = 27
    nombre = "victor"
    pais = "brazil"
 
doctor = Persona()
delattr(Persona, "pais")
print(doctor.nombre)
print(doctor.edad)
print(doctor.pais)