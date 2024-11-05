#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100  // Defina um tamanho máximo para as linhas

int main() {
    FILE *file = fopen("arquivo.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[MAX_LINE];
    
    // Leitura de cada linha do arquivo CSV
    while (fgets(line, MAX_LINE, file)) {
        // Remove a quebra de linha ao final
        line[strcspn(line, "\n")] = 0;

        // Separa os valores da linha por vírgula
        char *token = strtok(line, ",");
        while (token) {
            printf("%s ", token);  // Exibe cada valor da linha
            token = strtok(NULL, ",");
        }
        printf("\n");  // Pula para a próxima linha ao final de cada linha lida
    }

    fclose(file);
    return 0;
}