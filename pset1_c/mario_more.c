#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // Obtém a quantidade de linhas de blocos (#) que serão impressos.
    int altura;
    do 
    {
        altura = get_int ("Digite um número entre 1 e 8: ");  
    }
    while (altura < 1 || altura > 8);
        
    // Laço de repetição para impressão das pirâmides
    for (int linha = 0; linha < altura; linha++)
    {
        // Impressão da primeira pirâmide
        for (int coluna = 0; coluna < altura; coluna++)
        {
            // Verificação dos espaços para alinhamento dos blocos
            if (linha + coluna < altura - 1)
            {
              printf (" ");  
            }
            else 
            {
              printf ("#");   
            }
        }
        printf ("  ");
        
        // Impressão da segunda pirâmide
        for (int coluna = 0; coluna < altura; coluna++)
        {
            if (linha >= coluna)
            {
              printf ("#");
            }
        }
        printf ("\n");
    }
}
