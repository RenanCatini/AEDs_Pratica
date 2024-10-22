/*
GRUPO:
    - Lucas Lopes Baroni (2024.1.08.017)
    - Renan Catini Amaral (2024.1.08.---)
*/

#ifndef DEF_SEARCH_TREE
#define DEF_SEARCH_TREE

//Inclusão das estruturas do nó.
#include "arvores.h"

/*
 * @brief Cria um nó novo.
 * 
 * Essa função possui a finalidade de alocar
 * na memória principal um novo nó com determinado
 * valor.
 * 
 * @param value: valor inteiro do nó.
 * 
 * @return o endereço alocado para o elemento.
 */
no_def* createEl_DefTree(int value);


/*
 * @brief Busca na árvore determinado nó.
 * 
 * Essa função possui a finalidade de encontrar,
 * caso seja possível, um nó com determinado 
 * valor.
 * 
 * @param root: endereço da raiz da árvore.
 * 
 * @param rootDad: ponteiro de endereço que
 * armazenará o pai do nó buscado.
 * 
 * @param value: valor buscado.
 * 
 * @return o endereço do nó (NULL - não encontrado).
 */
no_def* searchEl_DefTree(no_def* root, no_def** rootDad, int value);


/*
 * @brief Insere na árvore um nó.
 * 
 * Essa função possui a finalidade de inserir,
 * caso seja possível, um novo nó na árvore. 
 * 
 * @param root: endereço da raiz da árvore.
 * 
 * @param el: endereço do novo nó.
 * 
 * @return endereço da raíz da árvore.
 */
no_def* addEl_DefTree(no_def* root, no_def* el);


/*
 * @brief Cuida da remoção de nós.
 * 
 * Essa função possui a finalidade de cuidar
 * de todo o processo de remoção de qualquer 
 * nó da árvore. 
 * 
 * @param root: endereço do nó a ser removido.
 * 
 * @return endereço da raíz da árvore.
 */
no_def* removeRoot_DefTree(no_def* root);


/*
 * @brief Remove um elemento da árvore.
 * 
 * Essa função possui a finalidade de remover,
 * caso seja possível, um nó presente na 
 * árvore. 
 * 
 * @param root: endereço da raiz da árvore.
 * 
 * @param value: valor do nó a ser removido.
 * 
 * @return endereço da raíz da árvore.
 */
no_def* removeEl_DefTree(no_def* root, int value);

/*
 * @brief Libera toda a memória alocada
 * pela árvore binária não balanceada.
 * 
 * @param root: endereço da raíz da árvore.
 */
void freeMemory_DefTree(no_def* root);

#endif 
