#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TO-DO: Solicite o valor inicial ao usuário
    int populacao_inicial;
    do
    {
        populacao_inicial = get_int("Insira a população inicial: ");
    }
    while (populacao_inicial < 9);

    // TO-DO: Solicite o valor final ao usuário
    int populacao_final;
    do
    {
        populacao_final = get_int("Insira a população final desejada: ");
    }
    while (populacao_final <= populacao_inicial);

    // TO-DO: Calcule o número de anos até o limite
    
    int anos = 0;
    int total = populacao_inicial;
    while (total < populacao_final)
    {
        total = total + ((total / 3) - (total / 4));
        anos++;
    }

    // TO-DO: Imprima o número de anos
    printf("Years: %i\n", anos);
}
