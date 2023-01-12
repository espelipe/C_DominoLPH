// Dom_LPH_view.cpp
// Grupo: Los Pollos Hermanos(LPH)
// Integrantes:
// Mateus Neves Eredia
// Felipe Casagrande Espel
// Joao Marcos Ribeirete Garbelini
// Murilo Bonventi Romani Pinto

#include "Dom_LPH_view.h"
#include <stdio.h>
#include <iostream>

// variável esc para escolha
int visual()
{
	int esc;

	// apresenta o menu do jogo

	printf("   _       _______   _    _ \n ");
	printf(" | |      |  __  | | |  | |\n ");
	printf(" | |      | |__) | | |__| |\n ");
	printf(" | |      |  ____| |  __  |\n ");
	printf(" | |____  | |      | |  | |\n");
	printf("  |______| |_|      |_|  |_|\n");
	printf("                       \n");
	printf("              MENU DO DOMINO LPH                          ");
	printf("\n-----------------------------------------------\n");
	printf("|1 - Iniciar jogo (2 jogadores)                |\n");
	printf("|2 - Iniciar jogo (contra o computador)        |\n");
	printf("|3 - Retornar ao jogo interrompido             |\n");
	printf("|4 - Regras gerais do jogo                     |\n");
	printf("|5 - Salvar o jogo                             |\n");
	printf("|6 - Recuperar o jogo salvo                    |\n");
	printf("|0 - Sair                                      |\n");
	printf("------------------------------------------------\n");
	printf("\nDigite a sua opcao: ");

	scanf("%d", &esc);

	printf("\n");

	return (esc);
}

// funcao para apresentar pecas
void apresentaPeca(struct statusPecas pecas[28])
{

	int k, u;

	// printf("Jogador 1: ");
	for (k = 0; k < 28; k++)
	{
		if (pecas[k].status == '1')
		{

			printf("A: [%d|%d]    ", pecas[k].Lado1, pecas[k].Lado2);
		}

		printf("\n");

		if (pecas[k].status == '2')
		{
			printf("B: [%d|%d]      ", pecas[k].Lado1, pecas[k].Lado2);
		}
	}

	printf("\n");
}

void maiorPeca()
{

	printf("MAIOR PECA:[%d/%d] -> ", aux.Lado1, aux.Lado2);
}

void pecasJogador1()
{

	printf("Jogador 1  \n");
}

void pecasJogador2()
{

	printf("Jogador 2  \n");
}

void pulaLinha()
{

	printf("\n");
}

void designMesa()
{
	printf("=");
}

void palavraMesa()
{

	printf("MESA");
}

void pecasDomino()
{

	int i;

	printf("[%d/%d] ", mesa[i].Lado1, mesa[i].Lado2);
}

void vezJogador1()
{

	printf("--------VEZ DO JOGADOR 1--------\n\n");
}

void vezJogador2()
{

	printf("--------VEZ DO JOGADOR 2--------\n\n");
}

void pecasEscrito()
{

	printf("PECAS:  ");
}

void pecaPossivel()
{

	printf("PECA POSSIVEL\n");
}

void ladoErrado()
{

	printf("Lado escolhido e impossivel.\n");
}

void opcaoErrada()
{

	printf("Opcao invalida de lado na mesa\n");
}

void numeracaoErrada()
{

	printf("Peca com numeracao errada");
}

void impossivelComprar()
{

	printf("Nao ha mais pecas para comprar");
}

void vezPassada()
{

	printf("VEZ PASSADA");
}

void aindaTem()
{

	printf("Ainda ha pecas para serem compradas ou jogadas\n");
}

void opcaoInvalida()
{

	printf("Opcao Invalida!");
}

void partidaFechada()
{

	printf("A partida ficou fechada (sem mais jogadas)\n");
}

void contagemPontos()
{

	printf("Pela contagem dos pontos\n");
}

void jogador1Venceu()
{

	printf("----------------------------------------\n");
	printf("             ___________\n");
	printf("            '._==_==_=_.'\n");
	printf("            .-|       |-.\n");
	printf("           | (|:.jog  |) |\n");
	printf("            '-|:. 1   |-'\n");
	printf("               ::.    /\n");
	printf("               '::. .'\n");
	printf("                 ) (\n");
	printf("               _.' '._\n");
	printf("\n-------------------------------------\n");
	printf("| Meus Parabens pela Grande vitoria |\n");
	printf("|              JOGADOR 1            |\n");
	printf("-------------------------------------\n");
	system("pause");
}

void jogador2Venceu()
{

	printf("----------------------------------------\n");
	printf("             ___________\n");
	printf("            '._==_==_=_.'\n");
	printf("            .-|       |-.\n");
	printf("           | (|:.jog  |) |\n");
	printf("            '-|:. 2   |-'\n");
	printf("               ::.    /\n");
	printf("               '::. .'\n");
	printf("                 ) (\n");
	printf("               _.' '._\n");
	printf("\n-------------------------------------\n");
	printf("| Meus Parabens pela Grande vitoria |\n");
	printf("|              JOGADOR 2            |\n");
	printf("-------------------------------------\n");
	system("pause");
}

void interrompeuJogo()
{

	printf("Interrrompeu o jogo\n");
}

void empateJogo()
{

	printf("Empate (jogadores tem o mesmo numero de pecas e somatorias)\n");
}

// funcao que apresenta a vez dos jogadores
void pecaDhr(struct statusPecas pecas[28], char z)
{

	int i, loc;
	loc = 1;
	if (z == '1')
	{
		printf("--------VEZ DO JOGADOR 1--------\n\n");
	}
	else
	{
		printf("--------VEZ DO JOGADOR 2--------\n\n");
	}
	printf("PECAS: ");
	for (i = 0; i < 28; i++)
	{
		if (pecas[i].status == z)
		{
			printf("%d.[%d|%d]  ", loc, pecas[i].Lado1, pecas[i].Lado2);
			loc++;
		}
	}
	printf("\n");
}

// funcao que apresenta as pecas
void pecasBacana(struct statusMesa mesa[28], int i)
{

	printf("[%d/%d] ", mesa[i].Lado1, mesa[i].Lado2);
}

// funcao que apresenta a escolha de peca
int fescpec(int loc)
{

	{
		int teste;
		printf("Escolha a peca para jogar (0 para desistir): ");
		scanf("%d", &teste);
		return teste;
	}
}

// apresenta o menu do jogador
int menuJogador(int test, int extE, int extD)
{

	int teste, saida;

	printf("\n---------------------------------------------\n");
	printf("|J - Jogar (possiveis %d ou %d)               |\n", extE, extD);
	printf("|C - Comprar                                |\n");
	printf("|P - Passar                                 |\n");
	printf("|S - Sair (interrorper o jogo)              |\n");
	printf("---------------------------------------------\n");
	printf("\nDigite a sua opcao: ");

	scanf("%s", &teste);

	if (teste == 'j' || teste == 'J')
	{
		saida = 1;
	}
	if (teste == 'c' || teste == 'C')
	{
		saida = 2;
	}
	if (teste == 's' || teste == 'S')
	{
		saida = 3;
	}
	if (teste == 'p' || teste == 'P')
	{
		saida = 4;
	}
	if (teste != 'j' && teste != 'J' && teste != 'c' && teste != 'C' && teste != 'p' && teste != 'P' && teste != 's' && teste != 'S')
	{
		saida = 5;
	}
	return saida;
}

// funcao que vai apresentar a escolha do lado da mesa ao jogar
int escolherLado(int lado)
{

	char teste;
	int saida;

	printf("Escolha o lado da Mesa: Esquerdo/Direito (E/D): ");
	scanf("%s", &teste);

	if (teste == 'e' || teste == 'E')
	{
		saida = 1;
	}
	if (teste == 'd' || teste == 'D')
	{
		saida = 2;
	}
	if (teste != 'e' && teste != 'E' && teste != 'd' && teste != 'D')
	{
		saida = 3;
	}

	return saida;
}

void jogosalvo()
{
	printf("O jogo foi salvo\n");
}

void falhasalvarjogo()
{
	printf("Nao foi possivel salvar o jogo\n");
}

void jogorecuperado()
{
	printf("O jogo foi recuperado\n");
}

void falhajogorecuperado()
{
	printf("Nao foi possivel recuperar o jogo\n");
}

// mensagens de salvamento
void erro1ARQPecas()
{
	printf("O arquivo ARQPecas não pode ser aberto para gravação\n");
}

void erro2ARQPecas()
{
	printf("Erro na gravacaodo arquivo ARQPecas");
}

void erro1ARQMesa()
{
	printf("O arquivo ARQMesa não pode ser aberto para gravação\n");
}

void erro2ARQMesa()
{
	printf("Erro na gravacaodo arquivo ARQMesa");
}

void erro1ARQJog()
{
	printf("O arquivo ARQJog não pode ser aberto para gravação\n");
}

void erro2ARQJog()
{
	printf("Erro na gravacaodo arquivo ARQJog");
}

void erro1ARQmesaP()
{
	printf("O arquivo ARQmesaP não pode ser aberto para gravação\n");
}

void erro2ARQmesaP()
{
	printf("Erro na gravacaodo arquivo ARQmesaP");
}

void erro1ARQTmesa()
{
	printf("O arquivo ARQTmesa não pode ser aberto para gravação\n");
}

void erro2ARQTmesa()
{
	printf("Erro na gravacaodo arquivo ARQTmesa");
}

void erro1ARQTcompr()
{
	printf("O arquivo ARQcompr não pode ser aberto para gravação\n");
}

void erro2ARQTcompr()
{
	printf("Erro na gravacaodo arquivo ARQcompr");
}

void erro1ARQempate()
{
	printf("O arquivo ARQempate não pode ser aberto para gravação\n");
}

void erro2ARQempate()
{
	printf("Erro na gravacaodo arquivo ARQempate");
}

// mensagens de recuperacao
void erro1recARQmesaP()
{
	printf("O arquivo ARQmesaP não pode ser aberto para leitura\n");
}

void erro2recARQmesaP()
{
	printf("Erro na leitura do arquivo ARQmesaP");
}

void erro1recARQPecas()
{
	printf("O arquivo ARQPecas não pode ser aberto para leitura\n");
}

void erro2recARQPecas()
{
	printf("Erro na leitura do arquivo ARQPecas");
}

void erro1recARQMesa()
{
	printf("O arquivo ARQMesa não pode ser aberto para leitura\n");
}

void erro2recARQMesa()
{
	printf("Erro na leitura do arquivo ARQMesa");
}

void erro1recARQJog()
{
	printf("O arquivo ARQJog não pode ser aberto para leitura\n");
}

void erro2recARQJog()
{
	printf("Erro na leitura do arquivo ARQJog");
}

void erro1recARQTmesa()
{
	printf("O arquivo ARQTmesa não pode ser aberto para leitura\n");
}

void erro2recARQTmesa()
{
	printf("Erro na leitura do arquivo ARQmesa");
}

void erro1recARQTcompr()
{
	printf("O arquivo ARQcompr não pode ser aberto para leitura\n");
}

void erro2recARQTcompr()
{
	printf("Erro na leitura do arquivo ARQcompr");
}

void erro1recARQempate()
{
	printf("O arquivo ARQemapte não pode ser aberto para leitura\n");
}

void erro2recARQempate()
{
	printf("Erro na leitura do arquivo ARQempate");
}

void RegrasDomino()
{
	printf("Para jogar domino usam-se 28 pecas\n");
	printf("Cada peca esta dividida em 2 lados numerados de 0 a 6\n");
	printf("O objetivo do jogo e utilizar todas as suas pecas antes do oponente e marcar pontos.\n");
	printf("O jogador que tiver menos pecas vence.\n");
}

void naohajogo()
{
	printf("Nao ha jogo para ser continuado");
}

void pecajogadabot(int i)
{
	printf("Peca jogada pelo bot [%d|%d]\n",pecas[i].Lado1,pecas[i].Lado2);
}

void pecacompradabot()
{
	   printf("Mais uma peca foi comprada pelo computador\n");
}

void vezpassadabot()
{
	printf("Vez passada pelo computador\n");
}

void jogadorBOTvenceu()
{

	printf("----------------------------------------\n");
	printf("             ___________\n");
	printf("            '._==_==_=_.'\n");
	printf("            .-|       |-.\n");
	printf("           | (|:.BOT  |) |\n");
	printf("            '-|:.     |-'\n");
	printf("               ::.    /\n");
	printf("               '::. .'\n");
	printf("                 ) (\n");
	printf("               _.' '._\n");
	printf("\n-------------------------------------\n");
	printf("| Voce perdeu para o computador     |\n");
	printf("|      mais sorte na proxima        |\n");
	printf("-------------------------------------\n");
	system("pause");
}

void jogadorPvenceu()
{

	printf("----------------------------------------\n");
	printf("             ___________\n");
	printf("            '._==_==_=_.'\n");
	printf("            .-|       |-.\n");
	printf("           | (|:.JOG  |) |\n");
	printf("            '-|:.     |-'\n");
	printf("               ::.    /\n");
	printf("               '::. .'\n");
	printf("                 ) (\n");
	printf("               _.' '._\n");
	printf("\n-------------------------------------\n");
	printf("|       Meus parabens jogador       |\n");
	printf("|      voce ganhou do computador    |\n");
	printf("-------------------------------------\n");
	system("pause");
}

void pecavsBOT(struct statusPecas pecas[28], char z)
{

	int i, loc;
	loc = 1;
	
	
printf("--------SUA RODADA JOGADOR--------\n\n");
	
	
	
		
	
	printf("PECAS: ");
	for (i = 0; i < 28; i++)
	{
		if (pecas[i].status == z)
		{
			printf("%d.[%d|%d]  ", loc, pecas[i].Lado1, pecas[i].Lado2);
			loc++;
		}
	}
	printf("\n");
}

void pecasJogadorP()
{

	printf("Jogador\n");
}

void pecasBOT()
{

	printf("Computador\n");
}

void erro1recARQespel()
{
	printf("O arquivo ARQespel não pode ser aberto para leitura\n");
}

void erro2recARQespel()
{
	printf("Erro na leitura do arquivo ARQespel");
}

void erro1ARQTespel()
{
	printf("O arquivo ARQespel não pode ser aberto para gravação\n");
}

void erro2ARQTespel()
{
	printf("Erro na gravacaodo arquivo ARQespel");
}
