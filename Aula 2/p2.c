#include <stdio.h>

int main(){
    //Para entrada de informações:
    /*
     Sempre segue a mesma lógica, colocar o valor digitado no
    endereço de memória separado na variável, não na variável
    em si.
    */
    int x;
    scanf("%d", &x);    
    printf("O valor digitado foi: %d", x);
    return 0;
}