// Dom_controller.cpp
// Grupo: Los Pollos Hermanos(LPH)
// Integrantes:
// Mateus Neves Eredia
// Felipe Casagrande Espel
// Joao Marcos Ribeirete Garbelini
// Murilo Bonventi Romani Pinto

#include "Dom_LPH_controller.h"
#include "Dom_LPH_view.cpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void controller()
{
    int esc;
    int i, k, test;
    do
    {
    	
        esc = visual();

        switch (esc)
        {
        case 1:
            espel = 1;
            iniciarJogo(pecas);

            break;

        case 2:
            espel = 2;
            jogcomputador();
            break;
        case 3:
            if (espel == 1)
            {
                continuarjogo();
            }
            if (espel == 2)
            {
                continuarjogoBOT();
            }
            if (espel != 1 && espel != 2)
            {
                naohajogo();
            }
            break;
        case 4:
            RegrasDomino();
            break;
        case 5:
            test = salvar();
            if (test == 0)
            {
                jogosalvo();
            }
            else
            {
                falhasalvarjogo();
            }
            break;
        case 6:
            recup();
            if (test == 0)
            {
                jogorecuperado();
            }
            else
            {
                falhajogorecuperado();
            }
            break;
        case 0:
            break;

        default:
            break;
        }

    } while (esc != 0);
}

// gera as pecas utilizadas no jogo
void gerarpeca(struct statusPecas pecas[28])
{

    int i, j, k = 0;

    for (i = 0; i <= 6; i++)
    {
        for (j = i; j <= 6; j++)
        {
            pecas[k].Lado1 = i;
            pecas[k].Lado2 = j;
            k++;
        }
    }
}

// esta funcao utiliza os valores criados anteriormente e os embaralha
void embaralharpecas(struct statusPecas pecas[28])
{

    int i, k;
    struct statusPecas aux;

    gerarpeca(pecas);

    // comando da biblioteca "time.h" utilizado para o embaralhamento das peças
    srand(time(NULL));

    // loop para embaralhas as peças(sem repeticao)
    for (i = 0; i < 28; i++)
    {
        k = rand() % 28;
        aux = pecas[i];
        pecas[i] = pecas[k];
        pecas[k] = aux;
    }
}

// esta funcao contem a logica do jogo
void iniciarJogo(struct statusPecas pecas[28])
{

    int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc;
    char test;
    int extD, extE;

    aux.status = ' ';
    aux.Lado1 = 0;
    aux.Lado2 = 1;
    compr = 13;
    mesaP = 1;
    lado = 0;
    empate = 0;
    Tmesa = 5;
    for (i = 0; i < 28; i++)
    {
        pecas[i].status = ' ';
    }

    embaralharpecas(pecas);

    // loop para determinar pecas do jogador 1
    for (i = 0; i <= 6; i++)
    {
        pecas[i].status = '1';
    }
    // loop para determinar pecas do jogador 2
    for (i = 7; i <= 13; i++)
    {
        pecas[i].status = '2';
    }

    // loop para descobrir qual jogador ira comecar o jogo
    for (i = 0; i <= 13; i++)
    {
        if (pecas[i].Lado1 == pecas[i].Lado2)
        {
            if (aux.Lado1 <= pecas[i].Lado1)
            {
                aux = pecas[i];
                u = i;
            }
            else
            {

                if (aux.Lado1 + aux.Lado2 <= pecas[i].Lado1 + pecas[i].Lado2)
                {
                    if (aux.Lado1 || aux.Lado2 > pecas[i].Lado1 || pecas[i].Lado2)
                    {
                        aux = pecas[i];
                        u = i;
                    }
                }
            }
        }
    }
    Tmesa = Tmesa + 7;
    maiorPeca();
    if (pecas[u].status == '1')
    {
        pecasJogador1();
    }
    else
    {
        pecasJogador2();
    }
    pulaLinha();
    mesa[0].Lado1 = aux.Lado1;
    mesa[0].Lado2 = aux.Lado2;
    extE = mesa[0].Lado1;
    extD = mesa[0].Lado2;

    if (pecas[u].status == '1')
    {
        z = '2';
    }
    else
    {
        z = '1';
    }
    pecas[u].status = 'm';
    
	continuarjogo();
    
    
}

// esta funcao salva o jogo
int salvar()
{
    int i;

    FILE *fp;
    if ((fp = fopen("ARQPecas", "w")) == NULL)
    {
        erro1ARQPecas();
        return 1;
    }

    for (i = 0; i < 28; i++)
    {
        if (fwrite(&pecas[i], sizeof(struct statusPecas), 1, fp) != 1)
        {
            erro2ARQPecas();
            break;
        }
    }

    fclose(fp);

    if ((fp = fopen("ARQMesa", "w")) == NULL)
    {
        erro1ARQMesa();
        return 1;
    }

    for (i = 0; i < mesaP; i++)
    {
        if (fwrite(&mesa[i], sizeof(struct statusMesa), 1, fp) != 1)
        {
            erro2ARQMesa();
            break;
        }
    }

    fclose(fp);

    if ((fp = fopen("ARQJog", "w")) == NULL)
    {
        erro1ARQJog();
        return 1;
    }

    if (fwrite(&z, sizeof(z), 1, fp) != 1)
    {
        erro2ARQJog();
        return 1;
    }

    fclose(fp);

    if ((fp = fopen("ARQmesaP", "w")) == NULL)
    {
        erro1ARQmesaP();
        return 1;
    }

    if (fwrite(&mesaP, sizeof(mesaP), 1, fp) != 1)
    {
        erro2ARQmesaP();
        return 1;
    }

    fclose(fp);

    if ((fp = fopen("ARQTmesa", "w")) == NULL)
    {
        erro1ARQTmesa();
        return 1;
    }

    if (fwrite(&Tmesa, sizeof(Tmesa), 1, fp) != 1)
    {
        erro2ARQTmesa();
        return 1;
    }

    fclose(fp);

    if ((fp = fopen("ARQcompr", "w")) == NULL)
    {
        erro1ARQTcompr();
        return 1;
    }

    if (fwrite(&compr, sizeof(compr), 1, fp) != 1)
    {
        erro2ARQTcompr();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQempate", "w")) == NULL)
    {
        erro1ARQempate();
        return 1;
    }

    if (fwrite(&empate, sizeof(empate), 1, fp) != 1)
    {
        erro2ARQempate();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQespel", "w")) == NULL)
    {
        erro1ARQTespel();
        return 1;
    }

    if (fwrite(&espel, sizeof(espel), 1, fp) != 1)
    {
        erro2ARQTespel();
        return 1;
    }
    fclose(fp);

    return 0;
}

// esta funcao recupera o jogo salvo
int recup()
{
    int i;

    FILE *fp;

    if ((fp = fopen("ARQmesaP", "r")) == NULL)
    {
        erro1recARQmesaP();
        return 1;
    }

    if (fread(&mesaP, sizeof(mesaP), 1, fp) != 1)
    {
        erro2recARQmesaP();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQPecas", "r")) == NULL)
    {
        erro1recARQPecas();
        return 1;
    }

    for (i = 0; i < 28; i++)
    {
        if (fread(&pecas[i], sizeof(struct statusPecas), 1, fp) != 1)
        {
            erro2recARQPecas();
            return 1;
        }
    }
    fclose(fp);

    if ((fp = fopen("ARQMesa", "r")) == NULL)
    {
        erro1recARQMesa();
        return 1;
    }

    for (i = 0; i < mesaP; i++)
    {
        if (fread(&mesa[i], sizeof(struct statusMesa), 1, fp) != 1)
        {
            erro2recARQMesa();
            break;
        }
    }
    fclose(fp);

    if ((fp = fopen("ARQJog", "r")) == NULL)
    {
        erro1recARQJog();
        return 1;
    }
    if (fread(&z, sizeof(z), 1, fp) != 1)
    {
        erro2recARQJog();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQTmesa", "r")) == NULL)
    {
        erro1recARQTmesa();
        return 1;
    }
    if (fread(&Tmesa, sizeof(Tmesa), 1, fp) != 1)
    {
        erro2recARQTmesa();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQcompr", "r")) == NULL)
    {
        erro1recARQTcompr();
        return 1;
    }
    if (fread(&compr, sizeof(compr), 1, fp) != 1)
    {
        erro2recARQTcompr();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQempate", "r")) == NULL)
    {
        erro1recARQempate();
        return 1;
    }
    if (fread(&empate, sizeof(empate), 1, fp) != 1)
    {
        erro2recARQempate();
        return 1;
    }
    fclose(fp);

    if ((fp = fopen("ARQespel", "r")) == NULL)
    {
        erro1recARQespel();
        return 1;
    }
    if (fread(&espel, sizeof(espel), 1, fp) != 1)
    {
        erro2recARQespel();
        return 1;
    }
    fclose(fp);

    return 0;
}

// esta funcao continua o jogo de onde ele parou
void continuarjogo()
{
    int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc;
    char test;
    int extD, extE;

    extE = mesa[0].Lado1;
    extD = mesa[mesaP-1].Lado2;

    do
    {
        i = 0;

        do
        {
            designMesa();
            i++;
        } while (Tmesa - 1 != i);

        i = 0;
        pulaLinha();
        palavraMesa();
        do
        {

            pecasBacana(mesa, i);
            i++;
        } while (i < mesaP);
        pulaLinha();

        i = 0;
        do
        {
            designMesa();
            i++;
        } while (Tmesa - 1 != i);

        i = 0;
        pulaLinha();
        pulaLinha();

        pecaDhr(pecas, z);

        // menu jogador
        teste1 = menuJogador(teste1, extE, extD);

        cont = 0;
        switch (teste1)
        {
        case 1:

            loc = fescpec(loc);

            if (loc == 0)
            {
                break;
            }
            else
                for (i = 0; i <= 27; i++)
                {
                    if (pecas[i].status == z)
                    {
                        cont++;
                    }
                    if (cont == loc)
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            pecaPossivel();
                            empate = 0;
                            if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                            {

                                lado = escolherLado(lado);

                                if (lado == 1)
                                {
                                    if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                    {

                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        if (pecas[i].Lado1 == extE)
                                        {
                                            mesa[0].Lado1 = pecas[i].Lado2;
                                            mesa[0].Lado2 = pecas[i].Lado1;
                                            mesaP++;
                                            extE = mesa[0].Lado1;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tmesa = Tmesa + 6;
                                            break;
                                        }
                                        else if (pecas[i].Lado2 == extE)
                                        {
                                            mesa[0].Lado1 = pecas[i].Lado1;
                                            mesa[0].Lado2 = pecas[i].Lado2;
                                            mesaP++;
                                            extE = mesa[0].Lado1;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tmesa = Tmesa + 6;
                                            break;
                                        }
                                        else
                                        {
                                            ladoErrado();
                                        }
                                    }
                                }
                                if (lado == 2)
                                {

                                    if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                    {
                                        if (pecas[i].Lado1 == extD)
                                        {
                                            mesa[mesaP].Lado1 = pecas[i].Lado1;
                                            mesa[mesaP].Lado2 = pecas[i].Lado2;
                                            extD = mesa[mesaP].Lado2;
                                            mesaP++;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tmesa = Tmesa + 6;
                                            break;
                                        }
                                        else if (pecas[i].Lado2 == extD)
                                        {
                                            mesa[mesaP].Lado1 = pecas[i].Lado2;
                                            mesa[mesaP].Lado2 = pecas[i].Lado1;
                                            extD = mesa[mesaP].Lado2;
                                            mesaP++;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tmesa = Tmesa + 6;
                                            break;
                                        }
                                        else
                                            ladoErrado();
                                    }
                                }
                                if (lado == 3)
                                {

                                    opcaoErrada();
                                }
                            }
                            else
                            {
                                if (pecas[i].Lado1 == extE)
                                {
                                    for (N = mesaP; N >= 0; N--)
                                    {
                                        mesa[N].Lado1 = mesa[N - 1].Lado1;
                                        mesa[N].Lado2 = mesa[N - 1].Lado2;
                                    }
                                    mesa[0].Lado1 = pecas[i].Lado2;
                                    mesa[0].Lado2 = pecas[i].Lado1;
                                    mesaP++;
                                    extE = mesa[0].Lado1;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tmesa = Tmesa + 6;
                                    break;
                                }
                                else if (pecas[i].Lado2 == extE)
                                {
                                    for (N = mesaP; N >= 0; N--)
                                    {
                                        mesa[N].Lado1 = mesa[N - 1].Lado1;
                                        mesa[N].Lado2 = mesa[N - 1].Lado2;
                                    }
                                    mesa[0].Lado1 = pecas[i].Lado1;
                                    mesa[0].Lado2 = pecas[i].Lado2;
                                    mesaP++;
                                    extE = mesa[0].Lado1;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tmesa = Tmesa + 6;
                                    break;
                                }
                                else if (pecas[i].Lado1 == extD)
                                {
                                    mesa[mesaP].Lado1 = pecas[i].Lado1;
                                    mesa[mesaP].Lado2 = pecas[i].Lado2;
                                    extD = mesa[mesaP].Lado2;
                                    mesaP++;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tmesa = Tmesa + 6;
                                    break;
                                }
                                else if (pecas[i].Lado2 == extD)
                                {
                                    mesa[mesaP].Lado1 = pecas[i].Lado2;
                                    mesa[mesaP].Lado2 = pecas[i].Lado1;
                                    extD = mesa[mesaP].Lado2;
                                    mesaP++;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tmesa = Tmesa + 6;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            numeracaoErrada();
                            pulaLinha();
                            break;
                        }
                    }
                }
            if (cont < loc)
            {
                opcaoInvalida();
            }

            break;

        case 2:

            if (compr == 27)
            {

                impossivelComprar();
            }
            else
            {

                compr++;
                pecas[compr].status = z;
            }

            break;
        case 4:

            cont = 0;
            if (compr == 27)
            {
                for (i = 0; i < 27; i++)
                {

                    if (pecas[i].status == z)
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            cont++;
                        }
                    }
                }
                if (cont == 0)
                {
                    vezPassada();
                    empate++;
                    if (z == '1')
                    {
                        z = '2';
                    }
                    else
                    {
                        z = '1';
                    }
                }
                else
                {
                    aindaTem();
                }
            }
            else
            {
                pulaLinha();
                aindaTem();
            }
            break;

        case 3:

            final = 3;
            teste1 = 3;
            break;

        default:

            opcaoInvalida();
            break;
        }
        pulaLinha();

        cont = 0;
        cont2 = 0;

        if (empate == 2)
        {
            for (i = 0; i < 27; i++)
            {
                if (pecas[i].status == '1')
                {
                    cont++;
                }
                if (pecas[i].status == '2')
                {
                    cont2++;
                }
            }
            if (cont < cont2)
            {
                final = 1;
                teste1 = 3;
                partidaFechada();
                contagemPontos();
            }
            if (cont2 < cont)
            {
                final = 2;
                teste1 = 3;
                partidaFechada();
                contagemPontos();
            }
            if (cont == cont2)
            {
                cont = 0;
                cont2 = 0;

                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont = cont + pecas[i].Lado1;
                        cont = cont + pecas[i].Lado2;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2 = cont2 + pecas[i].Lado1;
                        cont2 = cont2 + pecas[i].Lado2;
                    }
                }
                if (cont < cont2)
                {
                    final = 1;
                    teste1 = 3;
                    partidaFechada();
                    contagemPontos();
                }
                if (cont2 < cont)
                {
                    final = 2;
                    teste1 = 3;
                    partidaFechada();
                    contagemPontos();
                }
                if (cont == cont2)
                {
                    final = 4;
                    teste1 = 3;
                    partidaFechada();
                    contagemPontos();
                }
            }
        }

        cont = 0;
        cont2 = 0;

        // loop para descborir quem ganhara o jogo em caso de empate
        for (i = 0; i < 28; i++)
        {
            if (pecas[i].status == '1')
            {
                cont++;
            }
            if (pecas[i].status == '2')
            {
                cont2++;
            }
        }

        if (cont == 0 && compr == 27)
        {
            final = 1;
            teste1 = 3;
        }
        if (cont2 == 0 && compr == 27)
        {
            final = 2;
            teste1 = 3;
        }
    } while (teste1 != 3);

    if (final == 1)
    {
        jogador1Venceu();
    }
    if (final == 2)
    {
        jogador2Venceu();
    }
    if (final == 3)
    {
        interrompeuJogo();
    }
    if (final == 4)
    {
        empateJogo();
    }
}

void jogcomputador()
{
    int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc, marco;
    char test;
    int extD, extE;

    aux.status = ' ';
    aux.Lado1 = 0;
    aux.Lado2 = 1;
    compr = 13;
    mesaP = 1;
    lado = 0;
    empate = 0;
    Tmesa = 5;
    for (i = 0; i < 28; i++)
    {
        pecas[i].status = ' ';
    }

    embaralharpecas(pecas);

    // loop para determinar pecas do jogador 1
    for (i = 0; i <= 6; i++)
    {
        pecas[i].status = '1';
    }
    // loop para determinar pecas do jogador 2
    for (i = 7; i <= 13; i++)
    {
        pecas[i].status = '2';
    }

    // loop para descobrir qual jogador ira comecar o jogo
    for (i = 0; i <= 13; i++)
    {
        if (pecas[i].Lado1 == pecas[i].Lado2)
        {
            if (aux.Lado1 <= pecas[i].Lado1)
            {
                aux = pecas[i];
                u = i;
            }
            else
            {

                if (aux.Lado1 + aux.Lado2 <= pecas[i].Lado1 + pecas[i].Lado2)
                {
                    if (aux.Lado1 || aux.Lado2 > pecas[i].Lado1 || pecas[i].Lado2)
                    {
                        aux = pecas[i];
                        u = i;
                    }
                }
            }
        }
    }
    Tmesa = Tmesa + 7;
    maiorPeca();
    if (pecas[u].status == '1')
    {
        
        pecasJogadorP();
    }
    else
    {
        pecasBOT();
    }
    pulaLinha();
    mesa[0].Lado1 = aux.Lado1;
    mesa[0].Lado2 = aux.Lado2;
    extE = mesa[0].Lado1;
    extD = mesa[0].Lado2;

    if (pecas[u].status == '1')
    {
        z = '2';
    }
    else
    {
        z = '1';
    }
    pecas[u].status = 'm';
    
	continuarjogoBOT(); 
}

void continuarjogoBOT()
{
    int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc, marco;
    char test;
    int extD, extE;

    extE = mesa[0].Lado1;
    extD = mesa[mesaP-1].Lado2;  
    do
    {
        if (z == '1')
        {
            i = 0;

            do
            {
                designMesa();
                i++;
            } while (Tmesa - 1 != i);

            i = 0;
            pulaLinha();
            palavraMesa();
            do
            {

                pecasBacana(mesa, i);
                i++;
            } while (i < mesaP);
            pulaLinha();

            i = 0;
            do
            {
                designMesa();
                i++;
            } while (Tmesa - 1 != i);

            i = 0;
            pulaLinha();
            pulaLinha();

            pecavsBOT(pecas,z);

            // menu jogador
            teste1 = menuJogador(teste1, extE, extD);

            cont = 0;
            switch (teste1)
            {
            case 1:

                loc = fescpec(loc);

                if (loc == 0)
                {
                    break;
                }
                else
                    for (i = 0; i <= 27; i++)
                    {
                        if (pecas[i].status == z)
                        {
                            cont++;
                        }
                        if (cont == loc)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                pecaPossivel();
                                empate = 0;
                                if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                                {

                                    lado = escolherLado(lado);

                                    if (lado == 1)
                                    {
                                        if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                        {

                                            for (N = mesaP; N >= 0; N--)
                                            {
                                                mesa[N].Lado1 = mesa[N - 1].Lado1;
                                                mesa[N].Lado2 = mesa[N - 1].Lado2;
                                            }
                                            if (pecas[i].Lado1 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado2;
                                                mesa[0].Lado2 = pecas[i].Lado1;
                                                mesaP++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tmesa = Tmesa + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado1;
                                                mesa[0].Lado2 = pecas[i].Lado2;
                                                mesaP++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tmesa = Tmesa + 6;
                                                break;
                                            }
                                            else
                                            {
                                                ladoErrado();
                                            }
                                        }
                                    }
                                    if (lado == 2)
                                    {

                                        if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                        {
                                            if (pecas[i].Lado1 == extD)
                                            {
                                                mesa[mesaP].Lado1 = pecas[i].Lado1;
                                                mesa[mesaP].Lado2 = pecas[i].Lado2;
                                                extD = mesa[mesaP].Lado2;
                                                mesaP++;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tmesa = Tmesa + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extD)
                                            {
                                                mesa[mesaP].Lado1 = pecas[i].Lado2;
                                                mesa[mesaP].Lado2 = pecas[i].Lado1;
                                                extD = mesa[mesaP].Lado2;
                                                mesaP++;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tmesa = Tmesa + 6;
                                                break;
                                            }
                                            else
                                                ladoErrado();
                                        }
                                    }
                                    if (lado == 3)
                                    {

                                        opcaoErrada();
                                    }
                                }
                                else
                                {
                                    if (pecas[i].Lado1 == extE)
                                    {
                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado2;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mesaP++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tmesa = Tmesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extE)
                                    {
                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mesaP++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tmesa = Tmesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado1 == extD)
                                    {
                                        mesa[mesaP].Lado1 = pecas[i].Lado1;
                                        mesa[mesaP].Lado2 = pecas[i].Lado2;
                                        extD = mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tmesa = Tmesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extD)
                                    {
                                        mesa[mesaP].Lado1 = pecas[i].Lado2;
                                        mesa[mesaP].Lado2 = pecas[i].Lado1;
                                        extD = mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tmesa = Tmesa + 6;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                numeracaoErrada();
                                pulaLinha();
                                break;
                            }
                        }
                    }
                if (cont < loc)
                {
                    opcaoInvalida();
                }

                break;

            case 2:

                if (compr == 27)
                {

                    impossivelComprar();
                }
                else
                {

                    compr++;
                    pecas[compr].status = z;
                }

                break;
            case 4:

                cont = 0;
                if (compr == 27)
                {
                    for (i = 0; i < 27; i++)
                    {

                        if (pecas[i].status == z)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                cont++;
                            }
                        }
                    }
                    if (cont == 0)
                    {
                        vezPassada();
                        empate++;
                        if (z == '1')
                        {
                            z = '2';
                        }
                        else
                        {
                            z = '1';
                        }
                    }
                    else
                    {
                        aindaTem();
                    }
                }
                else
                {
                    pulaLinha();
                    aindaTem();
                }
                break;

            case 3:

                final = 3;
                teste1 = 3;
                break;

            default:

                opcaoInvalida();
                break;
            }
            pulaLinha();

            cont = 0;
            cont2 = 0;

            if (empate == 2)
            {
                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont++;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2++;
                    }
                }
                if (cont < cont2)
                {
                    final = 1;
                    teste1 = 3;
                    partidaFechada();
                    contagemPontos();
                }
                if (cont2 < cont)
                {
                    final = 2;
                    teste1 = 3;
                    partidaFechada();
                    contagemPontos();
                }
                if (cont == cont2)
                {
                    cont = 0;
                    cont2 = 0;

                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            cont = cont + pecas[i].Lado1;
                            cont = cont + pecas[i].Lado2;
                        }
                        if (pecas[i].status == '2')
                        {
                            cont2 = cont2 + pecas[i].Lado1;
                            cont2 = cont2 + pecas[i].Lado2;
                        }
                    }
                    if (cont < cont2)
                    {
                        final = 1;
                        teste1 = 3;
                        partidaFechada();
                        contagemPontos();
                    }
                    if (cont2 < cont)
                    {
                        final = 2;
                        teste1 = 3;
                        partidaFechada();
                        contagemPontos();
                    }
                    if (cont == cont2)
                    {
                        final = 4;
                        teste1 = 3;
                        partidaFechada();
                        contagemPontos();
                    }
                }
            }

            cont = 0;
            cont2 = 0;

            // loop para descborir quem ganhara o jogo em caso de empate
            for (i = 0; i < 28; i++)
            {
                if (pecas[i].status == '1')
                {
                    cont++;
                }
                if (pecas[i].status == '2')
                {
                    cont2++;
                }
            }

            if (cont == 0 && compr == 27)
            {
                final = 1;
                teste1 = 3;
            }
            if (cont2 == 0 && compr == 27)
            {
                final = 2;
                teste1 = 3;
            }
        }

        if (z == '2' && teste1 != 3)
        {
            do
            {
                marco = 0;
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '2')
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            marco = 1;
                            empate = 0;
                            pecajogadabot(i);
                            if (pecas[i].Lado1 == extE)
                            {
                                for (N = mesaP; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mesaP++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tmesa = Tmesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extE)
                            {
                                for (N = mesaP; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mesaP++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tmesa = Tmesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado1 == extD)
                            {
                                mesa[mesaP].Lado1 = pecas[i].Lado1;
                                mesa[mesaP].Lado2 = pecas[i].Lado2;
                                extD = mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tmesa = Tmesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extD)
                            {
                                mesa[mesaP].Lado1 = pecas[i].Lado2;
                                mesa[mesaP].Lado2 = pecas[i].Lado1;
                                extD = mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tmesa = Tmesa + 6;
                                break;
                            }
                        }
                    }
                }
                if (marco == 0)
                {
                    if (compr == 27)
                    {
                        marco = 0;
                    }
                    else
                    {
                        compr++;
                        marco = 1;
                        pecacompradabot();
                        pecas[compr].status = z;
                    }
                }
                if (marco == 0)
                {
                    z = '1';
                    empate++;
                    vezpassadabot();
                }

                cont = 0;
                cont2 = 0;

                if (empate == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            cont++;
                        }
                        if (pecas[i].status == '2')
                        {
                            cont2++;
                        }
                    }
                    if (cont < cont2)
                    {
                        final = 1;
                        teste1 = 3;
                        partidaFechada();
                        contagemPontos();
                    }
                    if (cont2 < cont)
                    {
                        final = 2;
                        teste1 = 3;
                        partidaFechada();
                        contagemPontos();
                    }
                    if (cont == cont2)
                    {
                        cont = 0;
                        cont2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (pecas[i].status == '1')
                            {
                                cont = cont + pecas[i].Lado1;
                                cont = cont + pecas[i].Lado2;
                            }
                            if (pecas[i].status == '2')
                            {
                                cont2 = cont2 + pecas[i].Lado1;
                                cont2 = cont2 + pecas[i].Lado2;
                            }
                        }
                        if (cont < cont2)
                        {
                            final = 1;
                            teste1 = 3;
                            partidaFechada();
                            contagemPontos();
                        }
                        if (cont2 < cont)
                        {
                            final = 2;
                            teste1 = 3;
                            partidaFechada();
                            contagemPontos();
                        }
                        if (cont == cont2)
                        {
                            final = 4;
                            teste1 = 3;
                            partidaFechada();
                            contagemPontos();
                        }
                    }
                }

                cont = 0;
                cont2 = 0;

                // loop para descborir quem ganhara o jogo em caso de empate
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont++;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2++;
                    }
                }

                if (cont == 0 && compr == 27)
                {
                    final = 1;
                    teste1 = 3;
                }
                if (cont2 == 0 && compr == 27)
                {
                    final = 2;
                    teste1 = 3;
                }

            } while (z != '1');
        }

    } while (teste1 != 3);

    if (final == 1)
    {
        jogadorPvenceu();
    }
    if (final == 2)
    {
        jogadorBOTvenceu();
    }
    if (final == 3)
    {
        interrompeuJogo();
    }
    if (final == 4)
    {
        empateJogo();
    }
}
