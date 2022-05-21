#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cents25 = 25;
    float cents10 = 10;
    float cents05 = 05;
    float cents01 = 01;
    int moedas = 0;
    int moedas25 = 0;
    int moedas10 = 0;
    int moedas05 = 0;
    int moedas01 = 0;

    // Obtém valor do troco à ser devolvido
    float troco;
    do
    {
        troco = get_float("Digite o valor do troco: $ ");
    }
    while (troco < -0);

    // Transformar o valor do troco em inteiro
    int centavos = round(troco * 100);

    // Laços de repetição para encontrar quantidade de moedas de troco
    while (centavos >= cents01)
    {
        // Divisão para encontrar moedas de 25 centavos
        if (centavos >= cents25)
        {
            centavos = (centavos - cents25);
            moedas25++;
        }
        // Divisão para encontrar moedas de 10 centavos
        else if (centavos >= cents10) 
        {
            centavos = (centavos - cents10);
            moedas10++;
        }
        // Divisão para encontrar moedas de 05 centavos
        else if (centavos >= cents05)
        {
            centavos = (centavos - cents05);
            moedas05++;
        }
        //Divisão para encontrar moedas de 01 centavo
        else 
        {
            centavos = (centavos - cents01);
            moedas01++;
        }
    }
    // Totalização das moedas utilizadas
    moedas = (moedas25 + moedas10 + moedas05 + moedas01);
    printf("Serão necessárias %i moedas de 25 centavos\n", moedas25);
    printf("Serão necessárias %i moedas de 10 centavos\n", moedas10);
    printf("Serão necessárias %i moedas de 05 centavos\n", moedas05);
    printf("Serão necessárias %i moedas de 01 centavo\n", moedas01);
    printf("Totalizando %i moedas\n", moedas);
}
