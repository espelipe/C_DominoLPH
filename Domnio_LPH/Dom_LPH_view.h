// Dom_LPH_view.h
// Grupo: Los Pollos Hermanos(LPH)
// Integrantes:
// Mateus Neves Eredia
// Felipe Casagrande Espel
// Joao Marcos Ribeirete Garbelini
// Murilo Bonventi Romani Pinto

int visual();
void apresentaPeca(struct statusPecas pecas[28]);
void maiorPeca();
void pecasJogador1();
void pecasJogador2();
void pulaLinha();
void designMesa();
void palavraMesa();
void pecasDomino();
void pecaPossivel();
void ladoErrado();
void opcaoErrada();
void numeraecaoErrada();
void impossivelComprar();
void vezPassada();
void aindaTem();
void opcaoInvalida();
void partidaFechada();
void contagemPontos();
void jogador1Venceu();
void jogador2Venceu();
void interrompeuJogo();
void empateJogo();
void pecaDhr(struct statusPecas pecas[28], char z);
void pecasBacana(struct statusMesa mesa[28], int i);
int fescpec(int test);
int menuJogador(int test);
int escolherLado(int lado);
void erro1ARQPecas();
void erro2ARQPecas();
void erro1ARQMesa();
void erro2ARQMesa();
void erro1ARQJog();
void erro2ARQJog();
void erro1ARQmesaP();
void erro2ARQmesaP();
void erro1ARQTmesa();
void erro2ARQTmesa();
void erro1ARQTcompr();
void erro2ARQTcompr();
void erro1ARQempate();
void erro2ARQempate();
void erro1recARQmesaP();
void erro2recARQmesaP();
void erro1recARQPecas();
void erro2recARQPecas();
void erro1recARQMesa();
void erro2recARQMesa();
void erro1recARQJog();
void erro2recARQJog();
void erro1recARQTmesa();
void erro2recARQTmesa();
void erro1recARQTcompr();
void erro2recARQTcompr();
void erro1recARQempate();
void erro2recARQempate();
void jogosalvo();
void falhasalvarjogo();
void jogorecuperado();
void falhajogorecuperado();
void RegrasDomino();
void naohajogo();
void pecajogadabot(int i);
void pecacompradabot();
void vezpassadabot();
void jogadorBOTvenceu();
void jogadorPvenceu();
void pecavsBOT(struct statusPecas pecas[28], char z);
void pecasJogadorP();
void pecasBOT();
void erro1recARQespel();
void erro2recARQespel();
void erro1ARQTespel();
void erro2ARQTespel();
