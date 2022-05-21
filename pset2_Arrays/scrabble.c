#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Valores ASCII atribuídos para letras minúsculas do alfabeto
int letras_minusculas[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Declaração da função "compute_score"
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Aplicação da função "compute_score"
int compute_score(string word)
{
    int letra = 0;
    int total = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        letra = tolower(word[i]);
        for (int i2 = 0; i2 < 26; i2++) // Laços encadeados para comparar cada caractere do texto com o valor de "letras_minusculas"
        {
            if (letra == letras_minusculas[i2])
            {
                total += POINTS[i2];
            }
            else
            {
                total += 0;
            }
        }
        letra = 0;
    }
    return (total);
}
