#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int conteo_digitos(long numero);
int Verificación_Luhn(long numero);

const int AÑO = 2020;

int main(void)
{
    long numero;//this prompts for input
    printf("Número: ");
    scanf("%li", &numero);

    int largo = conteo_digitos(numero);    //sends input to conteo_digitos
    bool tamaño_correcto = (largo == 10);               //adaptar esto
    bool num_legitimo = (Verificación_Luhn(numero) % 10) == 0;    //Checks numero with Luhn's Algorithm
    if (tamaño_correcto && num_legitimo)
    {
        printf("\nNÚMERO VALIDO\n");
        long curso =  numero / (pow(10, (5))); // separa los primeros 5 digitos

        int grado = (curso / 10 == AÑO)? 11 : (11 - (curso / 10 - AÑO));
        char salon = (curso % 10) + 64;
        printf("Estudiante del curso %i%c\n\n", grado, salon);
    }
    else
    {
        printf("NÚMERO INVALIDO\n");
    }
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
int conteo_digitos(long numero)
{
    int totalDigits = 0;

    while (numero != 0)
    {
        numero = numero / 10;
        totalDigits ++;
    }
    return totalDigits;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
int Verificación_Luhn(long numero)       //This returns checksum results to be verified in main.
{
    int numeros[10]; //An Array called numeros is created to store each individual numero

    int ArrayIndex = 9;

    while (numero != 0) //almacena los numeros en el array
    {
        int Ultimo = numero % 10;
        numeros[ArrayIndex] = Ultimo;
        numero /= 10;
        ArrayIndex--;
    }

    int Sumatoria = 0;
    for (int j = 8; j >= 0; j -= 2) //suma los digitos de los numeros multiplicados por 2
    {
        int multiplicados = numeros[j] * 2;
        if (multiplicados >= 10)
        {
            multiplicados = (multiplicados / 10) + (multiplicados % 10);
        }
        Sumatoria += multiplicados;
    }
    for (int i = 9; i >= 0; i -= 2)     //suma el resto de los numeros
    {
        Sumatoria += numeros[i];
    }

    return Sumatoria;
}
