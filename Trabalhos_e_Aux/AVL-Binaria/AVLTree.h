/*
GRUPO:
    - Lucas Lopes Baroni (2024.1.08.017)
    - Renan Catini Amaral (2024.1.08.---)
*/

#ifndef AVL_SEARCH_TREE
#define AVL_SEARCH_TREE

//Inclusão das estruturas do nó.
#include "arvores.h"

/*
 * @brief Calcula a altura de um nó.
 * 
 * Essa função possui a finalidade de calcular
 * a altura de um nó.
 * 
 * @param n: endereço do nó.
 * 
 * @return altura (número inteiro).
 */
int getHeight_AVLTree(no_avl *n);


/*
 * @brief Obtém o maior número.
 * 
 * Essa função possui a finalidade de retornar
 * o maior número inteiro.
 * 
 * @param a: primeiro número inteiro.
 * 
 * @param b: segundo número inteiro.
 * 
 * @return o maior deles.
 */
int getMax_AVLTree(int a, int b);


/*
 * @brief Calcula o fator de balanceamento.
 * 
 * Essa função possui a finalidade de calcular
 * o fator de balanceamento de um nó. Considere
 * que ele é dado por:
 * 
 * altSubArvore_esquerda - altSubArvore_direita
 * 
 * @param n: endereço do nó.
 * 
 * @return o resultado do fator de balanceamento.
 */
int getBalance_AVLTree(no_avl *n);


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
no_avl* createEl_AVLTree(int value);


/*
 * @brief Realiza a rotação a direita.
 * 
 * Essa função possui a finalidade de 
 * rotacionar nós desbalanceados em uma
 * subárvore esquerda na AVL.
 * 
 * @param y: endereço do nó desabalanceado.
 * 
 * @return endereço do nó com a rotação
 * aplicada.
 */
no_avl* rightRotate_AVLTree(no_avl *y);


/*
 * @brief Realiza a rotação a esquerda.
 * 
 * Essa função possui a finalidade de 
 * rotacionar nós desbalanceados em uma
 * subárvore direira na AVL.
 * 
 * @param y: endereço do nó desabalanceado.
 * 
 * @return endereço do nó com a rotação
 * aplicada.
 */
no_avl* leftRotate_AVLTree(no_avl *y);


/*
 * @brief Adiciona determinado nó na árvore.
 * 
 * Essa função possui a finalidade de adicionar
 * um novo nó na estrutura da árvore seguindo
 * os princípios de balanceamento da AVL.
 * 
 * @param root: endereço da raiz da árvore.
 * 
 * @param value: valor do nó a ser adicionado.
 * 
 * @return endereço da raíz da árvore.
 */
no_avl* addEl_AVLTree(no_avl* root, int value);

/*
 * @brief Remove determinado nó na árvore.
 * 
 * Essa função possui a finalidade de encontrar
 * e ordenar a remoção de determinado nó seguindo
 * os príncipios de balanceamento da árvore AVL.
 * 
 * @param root: endereço da raiz da árvore.
 * 
 * @param value: valor do nó a ser removido.
 * 
 * @return endereço da raíz da árvore.
 */
no_avl* removeEl_AVLTree(no_avl* root, int value);


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
no_avl* removeRoot_AVLTree(no_avl* root);

/*
 * @brief Libera toda a memória alocada
 * pela árvore AVL.
 * 
 * @param root: endereço da raíz da árvore.
 */
void freeMemory_AVLTree(no_avl* root);

#endif 
