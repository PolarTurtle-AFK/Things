#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *arch;
    char *texto;

    texto = (char *)malloc(50*sizeof(char));

    arch = fopen("archivo1.txt","a+");

    if (arch == NULL)
        printf("\nEl archivo no existe o hubo un error al intentar abrirlo\n");
    else
    {
        //fputs("\nProbando es que se sabe",arch);
        printf("Digite un mensaje: ");
        fgets(texto,50,stdin);

        fputs(texto,arch);
        fclose(arch);
    }

    arch = fopen("archivo1.txt","r");
    fgets(texto,40,arch);

    printf("\nLos primeros 20 caracteres del archivo: \n\"%s\"",texto);
    fclose(arch);

    system("PAUSE");
    return 0;
}
