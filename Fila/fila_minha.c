#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Fila não encadeada, ou seja vetor!

typedef struct filaP_{
    int frente, fundo, max_tam;
    int tam_atual;
    int *itens;
}filaP;


filaP *cria_fila(int tamanho){
    filaP *fila = malloc(sizeof(filaP)); //*
    fila->max_tam = tamanho;
    fila->frente = -1;
    fila->fundo = -1;
    fila->tam_atual = 0;
    //O "vetor" fila começa na variavel itens
    fila->itens = malloc(fila->max_tam * sizeof(int));
    return fila;
}

bool ehCheia(filaP *fila){
    if(((fila->frente)+1) + fila->max_tam == fila->fundo){
        printf("Fila cheia!!!");
        return true;
    }
    return false;
}

bool ehVazia(filaP *fila){
    if(fila->frente == -1){
        puts("Fila Vazia!");
        return true;
    }
    return false;
}

void push(filaP *fila, int item){
    if(ehCheia(fila)) return;
    if(ehVazia(fila)) fila->fundo++;
    fila->frente++;
    fila->itens[fila->frente] = item;
    fila->tam_atual++;
}

void imprime(filaP *fila){
    for(int i = 0; i < fila->tam_atual; i++){
        printf("%d ", fila->itens[i]);
    }
}

int main(){
    filaP *fila1 = cria_fila(5);
    ehVazia(fila1);
    push(fila1, 3);
    push(fila1, 5);
    push(fila1, 6);
    imprime(fila1);
}