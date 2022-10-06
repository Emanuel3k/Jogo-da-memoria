/*
    PROJETO DESENVOLVIDO POR GELADO (https://github.com/Emanuel3k);
    2022/1 DO CURSO DE ANALISE E DESENVOLVIMENTO DE SISTEMAS (IFSC - CANOINHAS);
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
void menu();
void info();
void montarTabuleiro();
int analisarTabuleiro();

// FUNÇÃO PRINCIPAL DO CODIGO
void main()
{

    int linha1, column1, linha2, column2;
    int op, gameover = 0, segundo = 0, minuto = 0, hora = 0;
    time_t t_ini, t_fim;

    while (op != 0)
    {

        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            t_ini = time(NULL); // INICIO DO CRONOMETRO

            do
            {
                do
                {
                    do
                    {
                        system("cls");
                        montarTabuleiro();

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
                        montarTabuleiro();

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
                montarTabuleiro();

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
                    gameover = analisarTabuleiro();
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
            break;

        case 2:
            system("cls");
            info();
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            puts("Operacao Invalida!\nEscolhas Apenas uma das opcoes listadas.\n");
            break;
        }
    }
}

// FUNÇÕES

void menu()
{
    puts("0 - Sair");
    puts("1 - Jogar");
    puts("2 - Informacoes");
    puts("");
}

void info()
{
    puts("Este e um jogo da memoria desenvolvido por Emanuel Jesus Santos.");
    puts("Aluno do curso de analise e desenvolvimento de sistemas do insituto federal de Santa Catarina (IFSC) - Campus Canoinhas.");
    puts("");
    puts("Este jogo tem como proposito apresentar parte do conteudo que foi aprendido no primeiro modulo do curso.");
}

void montarTabuleiro()
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
int analisarTabuleiro()
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
