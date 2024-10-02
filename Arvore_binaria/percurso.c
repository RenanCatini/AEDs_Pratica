#include <stdio.h>
#include <stdio.h>

typedef struct no_{
    int valor;
    struct no_ *esquerda, *direita; 
}no;

no *novo_no(int item){
    no *temp = (no*)malloc(sizeof(no));
    temp->valor = item;
    temp->direita = temp->esquerda = NULL;

    return temp; 
}

no *inserir_no(no *no, int valor){
    //Se o no passado for igual a NULL, ele retorna o novo no inserido.
    if(no == NULL) return novo_no(valor);

    if(valor < no->valor)
        no->esquerda = inserir_no(no->esquerda, valor);
    else if(valor > no->valor)
        no->direita = inserir_no(no->direita, valor);

    return no;
}

void pre_ordem(no *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(no *raiz){
    if(raiz != NULL){
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(no *raiz){
    if(raiz != NULL){    
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void imprimir_arvore(no *raiz, int nivel_atual) {
    if (raiz == NULL) return;
    
    imprimir_arvore(raiz->direita, nivel_atual + 1);
    
    for (int i = 0; i < nivel_atual; i++)
        printf("\t");

    printf("%d\n", raiz->valor);
    imprimir_arvore(raiz->esquerda, nivel_atual + 1);
}


int main(){
    no *raiz = NULL;

    raiz = inserir_no(raiz, 5);
    raiz = inserir_no(raiz, 3);
    raiz = inserir_no(raiz, 2);
    raiz = inserir_no(raiz, 4);
    raiz = inserir_no(raiz, 7);
    raiz = inserir_no(raiz, 6);
    raiz = inserir_no(raiz, 8);

    printf("Pre-ordem:\n");
    pre_ordem(raiz);
    printf("\n\n");

    printf("Em-ordem:\n");
    em_ordem(raiz);
    printf("\n\n");

    printf("Pos-ordem:\n");
    pos_ordem(raiz);
    printf("\n\n");

    printf("Em niveis:\n");
    imprimir_arvore(raiz, 0);

    return 0;
}