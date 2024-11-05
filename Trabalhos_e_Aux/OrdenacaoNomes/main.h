//MAIN

#ifndef ORDENACAO_JOGAD
#define oRDENACAO_JOGAD

#define maxNome 50
#define maxLinha 9 //1149

typedef struct _jogador{
    char nome[maxNome];
    char posicao[20];
    char naturalidade[30];
    char clube[20];
    int idade;
}jogador;

jogador jogadores[maxLinha];

//Funcoes

void lerArquivo(const char *nomeArquivo);


#endif 

