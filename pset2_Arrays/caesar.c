#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Declaração da função para verificar se o valor da chave é numérico
bool check_key_value(string s);

int main(int argc, string argv[])
{
    // Verifica se existe outro argumento além da execução do programa e se o valor digitado é numérico
    if (argc != 2 || !check_key_value(argv[1]))
    {
      printf("Usage: ./caesar key\n");
      return (1);
    }

    // Transforma a chave em inteiro
    int key = atoi(argv[1]);
 
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
           char letra = 'A';
           if (islower(caracter))
           {
               letra = 'a';
           }
           printf("%c", (caracter - letra + key) % 26 + letra); //aplica a fórmula para criptografar o caracter
       }
       else
       {
           printf("%c", caracter);
       }
    }
    printf("\n");
    return (0);
}

// Executa a função para verificar se o valor da chave é numérico
bool check_key_value(string s)
{
    for (int j = 0, len2 = strlen(s); j < len2; j++)
    {
        if (!isdigit(s[j]))
        return false;
    }    
    return true;
}
