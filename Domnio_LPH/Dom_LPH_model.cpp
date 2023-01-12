// Dom_LPH_model.cpp
// Grupo: Los Pollos Hermanos (LPH)
// Integrantes:
// Mateus Neves Eredia
// Felipe Casagrande Espel
// Joao Marcos Ribeirete Garbelini
// Murilo Bonventi Romani Pinto

// struct utilizado para armazenar informações das peças do jogo
struct statusPecas
{

    char status;
    int Lado1;
    int Lado2;

} pecas[28], aux;

// struct utilizado para armazenar informacoes das mesa do jogo
struct statusMesa
{

    char status;
    int Lado1;
    int Lado2;

} mesa[28];

int mesaP;
char z;
int Tmesa;
int compr;
int empate;
int espel;
