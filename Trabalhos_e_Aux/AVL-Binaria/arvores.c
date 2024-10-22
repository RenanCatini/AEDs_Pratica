#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>       
#include "arvores.h"

// Inclusão dos códigos das árvores

#include "defaultSearchTree.h"
#include "AVLTree.h"

// Criação dos dois tipos de árvores (inicialmente vazias)

no_avl* root_avl = NULL;
no_def* root_def = NULL;


double arvore_binaria(int instancia_num) {
    double tempo = 0;

    // 1. Transformando a variável inteira @instancia_num em string

    char textNumber[12]; 
    sprintf(textNumber, "%d", instancia_num);

    // 2. Concatenando o caminho das instâncias com a variável @textNumber

    char fileName[15] = "instancias/";
    strcat(fileName, textNumber);

    // 3. Abrindo o arquivo da instância e criando variáveis de leitura

    FILE* readFile = fopen(fileName, "r");
    char readOperation;
    int readValue;

    // 4. Lendo o arquivo e executando as operações presentes nele

    while(fscanf(readFile, "%c %d", &readOperation, &readValue) != EOF){
        clock_t begin, end;
        switch (readOperation){
            case 'I':
                begin = clock();
                root_def = addEl_DefTree(root_def, createEl_DefTree(readValue));
                end = clock();
                break;
            case 'R':
                begin = clock();
                root_def = removeEl_DefTree(root_def, readValue);
                end = clock();
                break;
        }
        tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    fclose(readFile);

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    return (tempo);
}

double arvore_balanceada(int instancia_num) {
    double tempo = 0;

    // 1. Transformando a variável inteira @instancia_num em string

    char textNumber[12]; 
    sprintf(textNumber, "%d", instancia_num);

    // 2. Concatenando o caminho das instâncias com a variável @textNumber

    char fileName[15] = "instancias/";
    strcat(fileName, textNumber);

    // 3. Abrindo o arquivo da instância e criando variáveis de leitura

    FILE* readFile = fopen(fileName, "r");
    char readOperation;
    int readValue;

    // 4. Lendo o arquivo e executando as operações presentes nele

    while(fscanf(readFile, "%c %d", &readOperation, &readValue) != EOF){
        clock_t begin, end;
        switch (readOperation){
            case 'I':
                begin = clock();
                root_avl = addEl_AVLTree(root_avl, readValue);
                end = clock();
                break;
            case 'R':
                begin = clock();
                root_avl = removeEl_AVLTree(root_avl, readValue);
                end = clock();
                break;
        }
        tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    }

    fclose(readFile);
    
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    return (tempo);
}


int main(int argc, char* argv[]) {
    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = -1;
    instancia_num = atoi(argv[1]);
    if (instancia_num <= 0 || instancia_num > 10) {
        printf("Para executar o código, digite ./arvores x\nonde x é um número entre 1 e 10 que simboliza a instância utilizada\n");
        exit(0);
    }
    
    double tempo_n_balanceada = arvore_binaria(instancia_num);
    double tempo_balanceada = arvore_balanceada(instancia_num);

    printf("%f\n%f\n", tempo_n_balanceada, tempo_balanceada);

    // Desalocação da memória

    freeMemory_DefTree(root_def);
    freeMemory_AVLTree(root_avl);

    return (1);
}
