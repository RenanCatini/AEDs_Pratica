/*
*Algoritmo de arvore não balanceada e algoritmo de balanceamento
*Ele cria uma arvore balanceada apartir de um vetor.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_ *direita, *esquerda;
}no;


//Constroi a arvore balanceada apartir de um vetor.
no *construir(int V[], int E, int D){
    if(E > D) return NULL;
    int mid = (E + D)/2;

    no *novo_no = (no*)malloc(sizeof(no));
    novo_no->valor = V[mid];
    novo_no->esquerda = construir(V, E, mid-1);
    novo_no->direita = construir(V, mid+1, D);
    return novo_no;
}

//Imprime a arvore igual uma arvore
void imprimir_arvore(no *raiz, int nivel_atual) {
    if (raiz == NULL) return;
    
    imprimir_arvore(raiz->direita, nivel_atual + 1);
    
    for (int i = 0; i < nivel_atual; i++)
        printf("\t");

    printf("%d\n", raiz->valor);
    imprimir_arvore(raiz->esquerda, nivel_atual + 1);
}

int main(){
    int vetor[] = {2,4,6,8,10,12,14};
    int tamanho = sizeof(vetor)/4;
    no *raiz = construir(vetor, 0, tamanho-1);
    imprimir_arvore(raiz, 0);
}