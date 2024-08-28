#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    struct no_ *ant;
    int data;   
}no;

no *top = NULL;

void insere(int valor){
    no *tmp1 = malloc(sizeof(no));
    tmp1->data = valor;
    tmp1->ant = top;
    top = tmp1;
}

void imprime(){
    if(top == NULL){
        printf("\n-Lista vazia!\n");
        return;
    }

    no *tmp = top;
    do{
        printf("%d ", tmp->data);
        tmp = tmp->ant;
    }while(tmp != NULL);
    printf("\n");
} 

void remover(){
    no *tmp = top;
    if(top == NULL){
        printf("-Nenhum valor removido!\n");
        return;
    }
    top = top->ant;
    free(tmp);
    printf("-Valor removido!\n");
}

int main(){
    int opc, valor;
    do{
        printf("1-Inserir valor.\n");
        printf("2-Remover valor.\n");
        printf("3-Imprimir pilha.\n");
        printf("0-Sair\n");
        printf("->");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("\nDigite o valor: ");
            scanf("%d", &valor);
            insere(valor);
            break;
        
        case 2:
            remover();
            break;
        case 3:
            imprime();
            break;
        
        case 0: 
            break;
        
        default:
            break;
        }

        puts("");
    }while(opc != 0);

    return 0;    
}