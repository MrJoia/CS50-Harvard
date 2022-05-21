#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Obtém o texto que será analisado
    string texto = get_string("Digite o texto: ");

    // Identifica o número de letras, palavras, sentenças(frases) e caracteres especiais no texto
    int letras = 0;
    int palavras = 1;
    int frases = 0;
    int especiais = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (isalpha(texto[i]))
        {
            letras++;
        }
        else if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            frases++;
        }
        else if (isspace(texto[i]))
        {
            palavras++;
        }
        else
        {
            especiais++;
        }
    }

    // Aplica o índice Coleman-Liau
    float l = (float) letras / palavras * 100;
    float s = (float) frases / palavras * 100;
    float indice = 0.0588 * l - 0.296 * s - 15.8;
    int grade = lround(indice);

    // Imprime as grades conforme valor do índice
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
