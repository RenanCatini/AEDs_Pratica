#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

/*
*   Funções de abertura de arquivo.
*/
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
    return;
}

void Arquivar(const char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "w");

    fprintf(arquivo, "Nome,Posição,Naturalidade,Clube,Idade\n");
    for(int i = 0; i < maxLinha; i++){
        fprintf(arquivo, "%s,%s,%s,%s,%d\n", jogadores[i].nome, jogadores[i].posicao,
        jogadores[i].naturalidade, jogadores[i].clube, jogadores[i].idade);
    }
    fclose(arquivo);
}

/*
*   Funções de ordenação.
*/

void bubbleSort(Jogador *jogadores, int *comparacoes, int *trocas){
    *comparacoes = 0;
    *trocas = 0;
    Jogador tmp;

    for(int i = 0; i < maxLinha-1; i++){
        for(int j = 0; j < maxLinha-i-1; j++){
            (*comparacoes)++;
            if(strcmp(jogadores[j].nome, jogadores[j+1].nome) > 0){
                tmp = jogadores[j];
                jogadores[j] = jogadores[j+1];
                jogadores[j+1] = tmp;
                (*trocas)++;
            }
        }
    }
}

//QuickSort
int particionar(Jogador *jogadores, int min, int max, int *comparacoes, int *trocas){
    Jogador pivo = jogadores[max];
    int i = min - 1;

    for (int j = min; j < max; j++) {
        (*comparacoes)++;
        if (strcmp(jogadores[j].nome, pivo.nome) < 0) {
            i++;
            // Troca jogadores[i] e jogadores[j]
            Jogador temp = jogadores[i];
            jogadores[i] = jogadores[j];
            jogadores[j] = temp;
            (*trocas)++;
        }
    }

    Jogador temp = jogadores[i + 1];
    jogadores[i + 1] = jogadores[max];
    jogadores[max] = temp;
    (*trocas)++;

    return i + 1;
}

void quickSort(Jogador *jogadores, int min, int max, int *comparacoes, int *trocas) {
    if (min < max) {
        // Particiona o vetor
        int pi = particionar(jogadores, min, max, comparacoes, trocas);

        // Chama recursivamente Quick Sort nas duas sublistas
        quickSort(jogadores, min, pi - 1, comparacoes, trocas);
        quickSort(jogadores, pi + 1, max, comparacoes, trocas);
    }
}



int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <opção>\nOpções válidas: 1, 2, 3\n", argv[0]);
        return 1;
    }
    int opcao = atoi(argv[1]);
      
    int comp, trocas;
    clock_t I_Bbs, F_Bbs;

    lerArquivo("jogadores.csv");

    I_Bbs = clock();
    switch (opcao)
    {
    case 1:
        bubbleSort(jogadores, &comp, &trocas);
        printf("*Metodo escolhido: Simples.\n");
        break;
    
    case 2:

        printf("*Metodo escolhido: Otimo.\n");
        break;

    case 3:
        quickSort(jogadores, 0, maxLinha-1, &comp, &trocas);
        printf("*Metodo escolhido: Tempo linear.\n");
        break;

    default:
        break;
    }
    F_Bbs = clock();
    float tempo_gasto = (double)(F_Bbs - I_Bbs) / CLOCKS_PER_SEC * 1000.0;

    Arquivar("jog_ordenado.csv");

    printf("-Tempo gasto: %f\n", tempo_gasto);
    printf("-Numero de comparacoes: %d\n", comp);
    printf("-Numero de trocas: %d\n", trocas);
    printf("-Memoria gasta:\n");

    return 0;
}




/*Testar: Calculo de memoria
#include <sys/resource.h>

void print_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memória máxima usada: %ld KB\n", usage.ru_maxrss);
}
*/