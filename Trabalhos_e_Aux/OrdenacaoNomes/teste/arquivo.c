#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxLinha 10
#define maxNome 50

typedef struct _jogador{
    char nome[maxNome];
    char posicao[20];
    char naturalidade[30];
    char clube[20];
    int idade;
}jogador;


jogador jogadores[maxLinha];

void lerArquivo(const char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        puts("ERRO!");
        return;
    }

    char linha[100]; //Armazenar cada linha
    fgets(linha, sizeof(linha), arquivo); //Lê e ignora a primeira linha

    int i = 0;

    //Le cada linha do arquivo .csv
    while(fgets(linha, sizeof(linha), arquivo)){
        linha[strcspn(linha, "\n")] = 0;   //Remove quebra de linha
        char *item = strtok(linha, ",");   //Separa os valores por virgula

        strcpy(jogadores[i].nome, item);
        item = strtok(NULL, ",");

        strcpy(jogadores[i].posicao, item);
        item = strtok(NULL, ",");

        strcpy(jogadores[i].naturalidade, item);
        item = strtok(NULL, ",");

        strcpy(jogadores[i].clube, item);
        item = strtok(NULL, ",");

        jogadores[i].idade = atoi(item);  //converte de string para int
        
        i++;
    }
    puts("Finalizado com sucesso!");
    return;
}

int main(){
    lerArquivo("jogadores.csv");
    printf("%s\n", jogadores[5].nome);
    printf("%s\n", jogadores[3].clube);
    return 0;
}