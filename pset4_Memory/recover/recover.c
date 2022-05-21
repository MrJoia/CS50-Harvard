#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Verifica se existe outro argumento além da execução do programa
    if (argc != 2)
    {
      printf("Usage: ./ recuperar imagem\n");
      return 1;
    } 
    
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        return 2;
    }
    
    // Criação das variáveis que serão utilizadas para leitura e escrita dos arquivos
    BYTE buffer [512];
    int count = 0;
    FILE *img_pointer = NULL;
    char filename[8];
    
    // Repetir até o final do cartão: 
    while (fread(&buffer, 512, 1, card) == 1) 
    { 
        // Se iniciar um novo JPEG (0xff 0xd8 0xff 0xe*): 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) 
        { 
            // Se não for o primeiro JPEG, fecha o anterior 
            if (!(count == 0)) 
            { 
                fclose(img_pointer); 
            }
    
            // Inicializa o arquivo 
            sprintf(filename, "%03i.jpg", count); 
            img_pointer = fopen(filename, "w"); 
            count++; 
        }
        
        // Se o JPEG foi encontrado, escreve no arquivo 
        if (!(count == 0)) 
        { 
            fwrite(&buffer, 512, 1, img_pointer); 
        } 
    }
    fclose(card); 
    fclose(img_pointer);
    return 0; 
} 
