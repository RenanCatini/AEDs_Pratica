#include <stdio.h>
#include <stdlib.h>

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

//Funções recursivas... Estudar
no *buscar(no *No, int valor){
    if(No == NULL || No->valor == valor) 
        return No;
    
    if(No->valor > valor)
        return buscar(No->direita, valor);
    else  
        return buscar(No->esquerda, valor);  
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

//Fazer função de remoção de nó, e busca de nó pai//

no *busca_pai(no *No, int valor){
     if(No == NULL)
        return No;
    
    if(No->direita->valor == valor || No->esquerda->valor == valor)
        return No;
    
    if(No->valor > valor)
        return buscar(No->direita, valor);
    else  
        return buscar(No->esquerda, valor);
}

no *remocao(no *raiz, int valor){
    if(buscar(raiz, valor) == NULL) return NULL;


}

int main(){

}