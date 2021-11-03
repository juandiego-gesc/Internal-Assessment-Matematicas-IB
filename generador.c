//Atoi recovered from: https://stackoverflow.com/questions/7021725/how-to-convert-a-string-to-integer-in-c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
int atoi(const char *snum);
int Luhn(long numero);


const int AÑO = 2020; //aclarar que esto es asumiendo que los carnes se estan creando este ano

int main(int argc, char *argv[])
{
    if (argc > 3 || argc < 2)
    {
        printf("Uso: ./generador grado curso\n");
        return 1;
    }

    int grado = atoi(argv[1]);
    long prom = (grado == 11)? AÑO : (AÑO + (11 - grado));

    long salon = toupper(argv[2][0]) - 64;

    srand(time(0));
    long identificador = 0;
    for (int i = 4; i > 0; i--)
    {
        int r = rand() % 10;
        identificador += r * pow(10, (i - 1));
    }

    long numero_carné = (prom * pow(10, 6)) + (salon * pow(10, 5)) + (identificador * 10);
    int numero_validacion = 10 - (Luhn(numero_carné) % 10);
    numero_carné += numero_validacion;

    printf("\n%li\n\n\n\n", numero_carné);
}

int Luhn(long numero)
{
    //Array para almacenar números
    int numeros[10];

    int ArrayIndex = 9;
    while (numero != 0)
    {
        int Ultimo = numero % 10;
        numeros[ArrayIndex] = Ultimo;
        numero /= 10;
        ArrayIndex--;
    }

    int Sumatoria = 0;
    //Procesa cada tercer digito
    for (int j = 8; j >= 0; j -= 2) 
    {
        int multiplicados = numeros[j] * 2;
        if (multiplicados >= 10)
        {
            multiplicados = (multiplicados / 10) + (multiplicados % 10);
        }
        Sumatoria += multiplicados;
    }
    //Se añade el resto de los digitos a la sumatoria
    for (int i = 9; i >= 0; i -= 2)
    {
        Sumatoria += numeros[i];
    }

    return Sumatoria;
}

int atoi(const char* snum)
{
    int idx, strIdx = 0, accum = 0, numIsNeg = 0;
    const unsigned int NUMLEN = (int)strlen(snum);

    /* Check if negative number and flag it. */
    if(snum[0] == 0x2d)
        numIsNeg = 1;

    for(idx = NUMLEN - 1; idx >= 0; idx--)
    {
        /* Only process numbers from 0 through 9. */
        if(snum[strIdx] >= 0x30 && snum[strIdx] <= 0x39)
            accum += (snum[strIdx] - 0x30) * pow(10, idx);

        strIdx++;
    }

    /* Check flag to see if originally passed -ve number and convert result if so. */
    if(!numIsNeg)
        return accum;
    else
        return accum * -1;
}




//tal vez una funcion q, una vez ya tenga generados todos los numeros, los una en forma de string

/*para el input puedo hacer q me de algo en forma de string, luego mirar el numero de elementos para ver si tiene un curso de 1 o 2
digitos y con eso ver que procedimiento hago, si cojo el numero como esta o cojo los primeros dos elementos, los paso a numero,
multiplico el primero por 10 y los sumo*/

// o tal vez simplemente sea mas facil decidir yo como hago el input, nadie va a usar el programa.

// int curso;
    // printf("\nGrado: ");
    // scanf("%i", &curso);

//GH 2 0 2 0 4 8 7 9 2 4