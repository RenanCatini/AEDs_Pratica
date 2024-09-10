#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>

//"Vetor"
typedef struct filaP_{
    int frente, fundo, max_tam;
    int tam_atual;
    int *itens;
}filaP;

filaP* criar_fila(int tamanho) { 
    filaP* fila = malloc(sizeof(filaP)); 
    fila->max_tam = tamanho; 
	fila->frente = -1;
    fila->fundo = -1;
    fila->tam_atual = 0;
	fila->itens = (int*)malloc(fila->max_tam * sizeof(int)); 
	return fila; 
} 

bool ehCheia(filaP* fila) { 
	if((fila->frente + 1) % fila->max_tam == fila->fundo) {
        return (true);
    }
    return (false);
} 

bool ehVazia(filaP* fila) { 
    if (fila->frente == -1) {
        return (true);
    } 
    return (false);
} 

void push(filaP* fila, int item) { 
    if (ehCheia(fila)) {
		printf("\nPilha cheia. Impossível inserir elementos");
        return; 
    }
    if(ehVazia(fila)) fila->fundo++;
    fila->frente++;
    fila->tam_atual++;
    if(fila->frente == fila->max_tam + 1){
        fila->frente = 0;
    }
	fila->itens[fila->frente] = item; 
} 


int pop(filaP* fila) { 
	// Se a pilha estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(fila)) {
		printf("\nPilha  vazia. Impossível remover elementos");
        return -1; 
    }
    int retorno = fila->itens[fila->fundo];
    fila->fundo++;
    if(fila->frente == fila->max_tam + 1){
        fila->frente = 0;
    }
	return (retorno); 
} 

// int obtem_elemento(struct filaP* pilha) { 
// 	// Se a pilha estiver vazia, não tem como obter nenhum elemento
//     if (ehVazia(pilha)) {
// 		printf("\nPilha  vazia. Impossível obter elementos");
//         return INT_MIN; 
//     }
//     // Retorna o elemento do topo da pilha
// 	return pilha->items[pilha->topo]; 
// } 

void imprime(filaP *fila){
    for(int i = 0; i < fila->tam_atual; i++){
        printf("%d ", fila->itens[i]);
    }
}


int main() { 
    int val, n;
    bool aux;
    // Cria pilha com 5 posições
    filaP* filaO = criar_fila(5); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. Pilha vazia?");
        printf("\n5. Pilha cheia?");
	    printf("\n6. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(filaO , val);
                break;
            case 2: 
                printf("\nElemento retirado : %d",pop(filaO));
                break;
            case 3: 
                imprime(filaO);
                //printf("\nElemento do topo: %d",obtem_elemento(pilha));
                break;
            case 4: 
                aux = ehVazia(filaO);
                if (aux) {
                    printf("\nPilha vazia");
                } else {
                    printf("\nPilha não está vazia");
                }
                break;
            case 5: 
                aux = ehCheia(filaO);
                if (aux) {
                    printf("\nPilha cheia");
                } else {
                    printf("\nPilha não está cheia");
                }
                break;         
            case 6:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }