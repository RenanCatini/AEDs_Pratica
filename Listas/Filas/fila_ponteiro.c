#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_ {
    int item;
    struct node_ *prox;
}node;

typedef struct fila_apontadores_{
    struct node_ *frente, *fundo;
    int tam_atual;
}fila_apontadores;

fila_apontadores *criar_fila(){
    fila_apontadores *fila = malloc(sizeof(fila_apontadores));
    fila->fundo = NULL;
    fila->frente = NULL;
    fila->tam_atual = 0;
    return fila;
}

bool ehVazia(fila_apontadores *fila){
    return(fila->tam_atual == 0);
}

void push(fila_apontadores *fila, int valor){
    node *novo = malloc(sizeof(node));
    novo->item = valor;
    novo->prox = NULL;
    
    if(ehVazia(fila)){
        fila->frente = novo;
        fila->fundo = novo;
    }
    else{
        fila->fundo->prox = novo;
        fila->fundo = novo;
    }
    fila->tam_atual = fila->tam_atual + 1;
}

void imprimir(fila_apontadores *fila){
    if(ehVazia(fila)){
        printf("Fila Vazia!\n");
        return;
    }
    
    node *atual = fila->frente;
    printf("%d ", atual->item);
    while(atual->prox != NULL){
        atual = atual->prox;
        printf("%d ", atual->item);
    }
    puts("");
}

struct node_ *pop(fila_apontadores *fila){
    if(fila->tam_atual == 0) return NULL;
    node *tmp = fila->frente;
    fila->frente = fila->frente->prox;
    fila->tam_atual--;
    return tmp;
}

int obtem_elemento(fila_apontadores *fila){
    return fila->frente->item;
}

void menu(){
    printf("\n--- Menu ---\n");
    printf("1. Inserir elemento na fila (push)\n");
    printf("2. Remover elemento da fila (pop)\n");
    printf("3. Imprimir fila\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    fila_apontadores *fila = criar_fila();
    int opcao, valor;
    node *removido;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(fila, valor);
                printf("Valor %d inserido na fila.\n", valor);
                break;

            case 2:
                removido = pop(fila);
                if (removido) {
                    printf("Elemento removido: %d\n", removido->item);
                    free(removido);  // Liberar memória do nó removido
                } else {
                    printf("Fila Vazia! Nao ha elementos para remover.\n");
                }
                break;

            case 3:
                imprimir(fila);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}