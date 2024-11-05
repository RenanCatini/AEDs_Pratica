//MAIN

#ifndef ORDENACAO_JOGAD
#define oRDENACAO_JOGAD

#define maxNome 50
#define maxLinha 1149

typedef struct _jogador{
    char nome[maxNome];
    char posicao[20];
    char naturalidade[30];
    char clube[20];
    int idade;
}Jogador;

Jogador jogadores[maxLinha];

//Funcoes

void lerArquivo(const char *nomeArquivo);
void Arquivar(const char *nome_arquivo);

void bubbleSort(Jogador *jogadores, int *comparacoes, int *trocas);
int particionar(Jogador *jogadores, int min, int max, int *comparacoes, int *trocas);
void quickSort(Jogador *jogadores, int min, int max, int *comparacoes, int *trocas);



#endif 

