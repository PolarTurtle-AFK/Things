#polimorfismo con metodo
class Colombia:
    def capital(self):
        print("bogota")
    def idioma(self):
        print("español")
class Francia:
    def capital(self):
        print("paris")
    def idioma(self):
        print("frances")

 
colombiano = Colombia()
frances = Francia()
for pais in (colombiano,frances):
    pais.capital()
    pais.idioma()