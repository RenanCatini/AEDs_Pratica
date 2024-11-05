#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"


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
    fclose(arquivo);
    puts("Finalizado com sucesso!");
    return;
}



int main(){
    lerArquivo("jogadores.csv");
    
}