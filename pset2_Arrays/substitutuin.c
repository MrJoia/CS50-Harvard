#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Declaração da função para verificar se a chave não possui dígitos
bool check_key_value(string s);

int main(int argc, string argv[])
{
    // Verifica se existe 2 argumentos de linha de comando
    if (argc != 2)
    {
        printf("Usage: ./caesar key!\n");
        return (1);
    }
    // Verifica se chave possui 26 letras
    if (!check_key_value(argv[1]))
    {
        printf("Chave deve possuir 26 letras!\n");
        return (1);
    }
    // Verifica se não existem caracteres repetidos na chave
    int count = 0;
    bool erro;
    for (int i = 0; i < 26; i++)
    {
        for (int i2 = 0; i2 < 26; i2++)
        {
            if (argv[1][i] == argv[1][i2])
            {
                count++;
            }
        }
        if (count > 1)
        {
            erro = true;
        }
        count = 0;
        if (erro)
        {
            printf("Chave não deve conter caracteres repeditos!\n");
            return (1);
        }
    }

    // Armazena a chave imputada na linha de comando em uma variável
    string key = argv[1];

    // Obtém o texto simples
    string plaintext = get_string("plaintext: ");

    // Imprime o texto cifrado
    printf("ciphertext: ");

    // Laço de repetição para criptografar o texto
    int n = strlen(plaintext);
    for (int i = 0; i < n; i++)
    {
        char caracter = plaintext[i];
        if (isalpha(caracter))
        {
            int l = (tolower(plaintext[i]) - 97);
            if (islower(plaintext[i]))
            {
                printf("%c", tolower(argv[1][l]));
            }
            else
            {
                printf("%c", toupper(argv[1][l]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return (0);
}

// Executa a função para verificar se a chave não possui dígitos
bool check_key_value(string s)
{
    for (int j = 0, len2 = strlen(s); j < len2; j++)
    {
        if (!isalpha(s[j]))
        {
            return (false);
        }
        else if (strlen(s) != 26)
        {
            return (false);
        }
    }
    return (true);
}
