#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, n2 = width; j < n2; j++)
        {
            int average = lround((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
            
            // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
            if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }    
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    int originalBlue = 0;
    int originalGreen = 0;
    int originalRed = 0;

    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, n2 = (round(width / 2)); j < n2; j++)
        {
            // Armazena em variáveis temporárias as cores Azul, Verde e Vermelho do pixel à esquerda (imagme[i][j])
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // Realizando a troca das cores do pixel à esquerda pelas cores do pixel correlacionado à direita
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            // Substitui as cores do pixel à direita pelas cores salvas anteriormente nas variáveis temporárias
            image[i][width - j - 1].rgbtRed = originalRed;
            image[i][width - j - 1].rgbtGreen = originalGreen;
            image[i][width - j - 1].rgbtBlue = originalBlue;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // Declaração de variáveis para controle da posição dos pixels
    int altura_base = height - 1;
    int largura_base = width - 1;

    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, n2 = width; j < n2; j++)
        {
            // Verifica se a posição do pixel [i][j] não está na borda e, portanto, será considerada uma Matriz 3x3 de pixels para cálculo da média RGB
            if (i >= 1 && i <= altura_base && j >= 1 && j <= largura_base)
            {
                // Calcula a média de azul considerando 9 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                            image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);

                // Calcula a média de verde considerando 9 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                            image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                            image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);

                // Calcula a média de vermelho considerando 9 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                            image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se o pixel [i] não está nas bordas e se j está alinhado à esquerda, neste caso, será considerada uma Matriz 3x2 de pixels para cálculo da média RGB
            else if (i >= 1 && i <= altura_base && j == 0)
            {
                // Calcula a média de azul considerando 6 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                            image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);

                // Calcula a média de verde considerando 6 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                            image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                            image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);

                // Calcula a média de vermelho considerando 6 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                          image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                          image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se o pixel [i] não está nas bordas e se j está alinhado à direita, neste caso, será considerada uma Matriz 3x2 de pixels para cálculo da média RGB
            else if (i >= 1 && i <= altura_base && j == width)
            {
                // Calcula a média de azul considerando 6 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                            image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                            image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6.0);

                // Calcula a média de verde considerando 6 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                            image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                            image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6.0);

                // Calcula a média de vermelho considerando 6 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                          image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                                          image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se o pixel [i] está na posição 0 e se j não está nas bordas, neste caso, será considerada uma Matriz 3x2 de pixels para cálculo da média RGB
            else if (i == 0 && j >= 1 && j <= largura_base)
            {
                // Calcula a média de azul considerando 6 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);

                // Calcula a média de verde considerando 6 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                            image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);

                // Calcula a média de vermelho considerando 6 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se o pixel [i] está na última posição da alutra e se j não está nas bordas, neste caso, será considerada uma Matriz 3x2 de pixels para cálculo da média RGB
            else if (i == height && j >= 1 && j <= largura_base)
            {
                // Calcula a média de azul considerando 6 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6.0);

                // Calcula a média de verde considerando 6 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                            image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.0);

                // Calcula a média de vermelho considerando 6 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se os pixeis [i] está na borda superior [j] alinhado à esquerda, neste caso, será considerada uma Matriz 2x2 de pixels para cálculo da média RGB
            else if (i == 0 && j == 0)
            {
                // Calcula a média de azul considerando 4 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);

                // Calcula a média de verde considerando 4 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                            image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);

                // Calcula a média de vermelho considerando 4 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se os pixeis [i] está na borda superior [j] alinhado à direita, neste caso, será considerada uma Matriz 2x2 de pixels para cálculo da média RGB
            else if (i == 0 && j == width)
            {
                // Calcula a média de azul considerando 4 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                            image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.0);

                // Calcula a média de verde considerando 4 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                            image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4.0);

                // Calcula a média de vermelho considerando 4 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Verifica se os pixeis [i] está na borda inferior e [j] alinhado à esquerda, neste caso, será considerada uma Matriz 2x2 de pixels para cálculo da média RGB
            else if (i == height && j == 0)
            {
                // Calcula a média de azul considerando 4 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4.0);

                // Calcula a média de verde considerando 4 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                            image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4.0);

                // Calcula a média de vermelho considerando 4 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }

            // Se os pixeis [i] está na borda inferior e [j] alinhado à direita, neste caso, será considerada uma Matriz 2x2 de pixels para cálculo da média RGB
            else
            {
                // Calcula a média de azul considerando 4 pixels ao redor do pixel [i][j];
                int average_blue = lround((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                            image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4.0);

                // Calcula a média de verde considerando 4 pixels ao redor do pixel [i][j];
                int average_green = lround((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                            image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4.0);

                // Calcula a média de vermelho considerando 4 pixels ao redor do pixel [i][j];
                int average_red = lround((image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                                            image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4.0);

                // Atribui a média de Vermelho, Verde e Azul para o pixel [i][j]
                image[i][j].rgbtBlue = average_blue;
                image[i][j].rgbtGreen = average_green;
                image[i][j].rgbtRed = average_red;
                
                // Limita o tamanho máximo do pixel em 255 pontos de Vermelho, Verde e Azul
                if (image[i][j].rgbtBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }                
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Initialise Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise ints
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;
            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;

            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    Gy_red += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }

            // Calculate Sobel operator
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Cap at 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // Assign new values to pixels
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
