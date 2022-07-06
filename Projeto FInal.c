/*
    PROJETO DESENVOLVIDO POR EMANUEL JESUS SANTOS (Gelado);
    1º SEMESTRE DO CURSO DE ANALISE E DESENVOLVIMENTO DE SISTEMAS (IFSC - CANOINHAS);
*/

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//  DEFINIR O TABULEIRO DEITADO COM 'X'
#define coberto 'X'

// TABULEIRO
char tabu[6][6] =
    {
        'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R',
        'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R'};

//  PARA MOSTRAR QUAIS PEÇAS JA FORAM MOSTRADAS
char tabu_virado[6][6] =
    {
        'X', 'X', 'X', 'X', 'X', 'X',
        'X', 'X', 'X', 'X', 'X', 'X',
        'X', 'X', 'X', 'X', 'X', 'X',
        'X', 'X', 'X', 'X', 'X', 'X',
        'X', 'X', 'X', 'X', 'X', 'X',
        'X', 'X', 'X', 'X', 'X', 'X'};

// PROTOTIPO DAS FUNCOES
void montar_tabu();  // IMRPIMIR O TABULEIRO
int analisar_tabu(); // ANALISA SE TODAS AS PEÇAS FORAM VIRADAS

// FUNÇÃO PRINCIPAL DO CODIGO
int main()
{

    int linha1, column1, linha2, column2;
    int op, gameover = 0, segundo = 0, minuto = 0, hora = 0;
    char menu;
    time_t t_ini, t_fim;

    do
    {
        //  MENU DO JOGO
        puts("\t\t\t\t\t***JOGO DA MEMORIA***\t\t\n");
        puts("\t\t\t\t\t(1) Jogar\t");
        puts("\t\t\t\t\t(2) Intrucoes\t");
        puts("\t\t\t\t\t(3) Sair\t");
        puts("\t\t\t\t\tDigite a opcao desejada: ");
        scanf("%d", &op);

        if (op == 1)
        {
            t_ini = time(NULL); // INICIO DO CRONOMETRO

            do
            {
                do
                {
                    do
                    {
                        system("cls");
                        montar_tabu();

                        puts("Digite a linha e a coluna");
                        scanf("%d\n%d", &linha1, &column1);

                        if (linha1 < 0 || linha1 > 5 || column1 > 5 || column1 < 0)
                        {
                            puts("Numero invalido!\nDigite um valor entre 0 e 5.");
                            Sleep(2000);
                        }

                    } while (linha1 < 0 || linha1 > 5 || column1 > 5 || column1 < 0);

                    if (tabu_virado[linha1][column1] != coberto)
                    {
                        puts("Opa, essa casa ja foi descoberta");
                        Sleep(2000);
                    }

                } while (tabu_virado[linha1][column1] != coberto);

                tabu_virado[linha1][column1] = tabu[linha1][column1];

                do
                {
                    do
                    {
                        system("cls");
                        montar_tabu();

                        puts("Digite a linha e a coluna");
                        scanf("%d\n%d", &linha2, &column2);

                        if (linha2 < 0 || linha2 > 5 || column2 > 5 || column2 < 0)
                        {
                            puts("Numero invalido!\nDigite um valor entre 0 e 5.");
                            Sleep(2000);
                        }

                    } while (linha2 < 0 || linha2 > 5 || column2 > 5 || column2 < 0);

                    if (tabu_virado[linha2][column2] != coberto)
                    {
                        puts("Opa, essa casa ja foi descoberta");
                        Sleep(2000);
                    }

                } while (tabu_virado[linha2][column2] != coberto);

                tabu_virado[linha2][column2] = tabu[linha2][column2];

                system("cls");
                montar_tabu();

                if (tabu[linha1][column1] != tabu[linha2][column2])
                {
                    puts("Errou!");
                    Sleep(2000);
                    tabu_virado[linha1][column1] = coberto;
                    tabu_virado[linha2][column2] = coberto;
                }
                else
                {
                    puts("Boa!!");
                    Sleep(1000);
                    gameover = analisar_tabu();
                }

            } while (!gameover);

            t_fim = time(NULL);               // FINALIZA O CRONOMETRO
            segundo = difftime(t_fim, t_ini); // GRAVA A DIFERENÇA DO FIM COM A DO INICIO DO CRONOMETRO EM SEGUNDOS
            if (segundo > 60)
            { // CONVERTE O TEMPO DE SEGUNDOS PARA HORAS E MINUTOS
                minuto = segundo / 60;
                segundo = segundo % 60;
            }
            if (minuto > 60)
            {
                hora = minuto / 60;
                minuto = minuto % 60;
            }
            printf("\nO Jogador demorou %dh:%dm:%ds.\n\n", hora, minuto, segundo); // PRINTA O TEMPO DA PARTIDA
            Sleep(5000);
            system("cls");
        }

        if (op == 2)
        {
            system("cls");
            puts("\n\nO jogo da memoria e um classico jogo formado por pecas que apresentam uma figura em um dos lados.\nCada figura se repete em duas peças diferentes.\nPara comecar o jogo, as pecas sao postas com as figuras voltadas para baixo, para que nao possam ser vistas.\nCada participante deve, na sua vez, virar duas pecas e deixar que todos as vejam. Caso as figuras sejam iguais, o participante deve recolher consigo esse par e jogar novamente.\nSe forem pecas diferentes, estas devem ser viradas novamente, e sendo passada a vez ao participante seguinte.\nGanha o jogo quem tiver mais pares no final do jogo.\n\n\t\t\t\t\t\tBy: Wikipedia\n");
            scanf("%c", &menu);
            system("pause");
            system("cls");
        }
        if (op == 3)
        {
            exit(3);
        }
    } while (menu);

    system("pause");
    return 0;
}

// MONTAR O TABULEIRO
void montar_tabu()
{
    printf("   0 1 2 3 4 5\n");
    for (int linha = 0; linha <= 5; linha++)
    {
        printf("%d  ", linha);
        for (int column = 0; column <= 5; column++)
        {
            if (tabu_virado[linha][column] != coberto)
            {
                printf("%c|", tabu_virado[linha][column]);
            }
            else if (linha < 5)
            {
                printf("_|");
            }
            else
            {
                printf(" |");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

// ANALISAR O JOGO
int analisar_tabu()
{
    int qt;
    for (int linha = 0; linha <= 5; linha++)
    {
        for (int column = 0; column <= 5; column++)
        {
            if (tabu_virado[linha][column] != coberto)
            {
                qt++;
            }
        }
    }
    if (qt == 36)
    {
        return 1;
    }
    return 0;
}