#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>

// Estrutura da fila circular
struct fila { 
    int frente; 
    int traseira; 
    int tamanho; 
    int capacidade; 
    int* items; 
}; 

// Função para criar a fila circular
struct fila* criar_fila(int capacidade) { 
    struct fila* fila = (struct fila*)malloc(sizeof(struct fila)); 
    fila->capacidade = capacidade; 
    fila->tamanho = 0; 
    fila->frente = 0; 
    fila->traseira = -1; 
    fila->items = (int*)malloc(fila->capacidade * sizeof(int)); 
    return fila; 
} 

// Função para verificar se a fila está cheia
bool ehCheia(struct fila* fila) { 
    return (fila->tamanho == fila->capacidade);
} 

// Função para verificar se a fila está vazia
bool ehVazia(struct fila* fila) { 
    return (fila->tamanho == 0);
} 

// Função para adicionar um item à fila
void enfileirar(struct fila* fila, int item) { 
    if (ehCheia(fila)) {
        printf("\nFila cheia. Impossível adicionar elementos");
        return; 
    }
    // Calcula o próximo índice circular
    fila->traseira = (fila->traseira + 1) % fila->capacidade; 
    fila->items[fila->traseira] = item; 
    fila->tamanho++; 
} 

// Função para remover um item da fila
int desenfileirar(struct fila* fila) { 
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1; 
    }
    int item = fila->items[fila->frente]; 
    fila->frente = (fila->frente + 1) % fila->capacidade; 
    fila->tamanho--; 
    return item; 
} 

// Função para obter o item na frente da fila
int obtem_elemento(struct fila* fila) { 
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível obter elementos");
        return INT_MIN; 
    }
    return fila->items[fila->frente]; 
} 

int main() { 
    int val, n;
    bool aux;
    // Cria a fila com 5 posições
    struct fila* fila = criar_fila(5); 
    do {
        printf("\n************************* MENU ************************");
        printf("\n1. Enfileirar");
        printf("\n2. Desenfileirar");
        printf("\n3. Obtém elemento");
        printf("\n4. Fila vazia?");
        printf("\n5. Fila cheia?");
        printf("\n6. Sair");
        printf("\nDigite sua escolha : ");
        scanf("%d",&n);
        switch(n) {
            case 1: 
                printf("\nDigite o valor ");
                scanf("%d",&val);
                enfileirar(fila , val);
                break;
            case 2: 
                printf("\nElemento removido : %d", desenfileirar(fila));
                break;
            case 3: 
                printf("\nElemento na frente: %d", obtem_elemento(fila));
                break;
            case 4: 
                aux = ehVazia(fila);
                if (aux) {
                    printf("\nFila vazia");
                } else {
                    printf("\nFila não está vazia");
                }
                break;
            case 5: 
                aux = ehCheia(fila);
                if (aux) {
                    printf("\nFila cheia");
                } else {
                    printf("\nFila não está cheia");
                }
                break;         
            case 6:
                free(fila->items); // Libera a memória do vetor de itens
                free(fila); // Libera a memória da estrutura da fila
                return (0);
                break;
            default: 
                printf("\nOpção errada!");
                break;
        }
    } while(1);
    
    return (0);
}
