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
    struct node_ *itens;
}fila_apontadores;

fila_apontadores *criar_fila(){
    fila_apontadores *fila = malloc(sizeof(fila_apontadores));
    fila->fundo = NULL;
    fila->frente = NULL;
    fila->tam_atual = 0;
    fila->itens = malloc(sizeof(node));
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
    if(ehVazia(fila) == 0) return NULL;
    struct node_ *temp = fila->frente;
    fila->frente = fila->frente->prox;
    fila->tam_atual--;
}


void main(){

    fila_apontadores *fila1 = criar_fila();
    push(fila1, 10);
    push(fila1, 20);
    push(fila1, 15);
    push(fila1, 35);
    imprimir(fila1);
    pop(fila1);
    pop(fila1);
    pop(fila1);
    imprimir(fila1);
    pop(fila1);
    imprimir(fila1);
    pop(fila1);
    imprimir(fila1);
}