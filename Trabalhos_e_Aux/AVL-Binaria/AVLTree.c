#include <stdio.h> 
#include <stdlib.h> 
#include "AVLTree.h"
  
int getHeight_AVLTree(no_avl *n){ 
    return (n == NULL) ? 0 : n->height; 
} 
int getMax_AVLTree(int a, int b){ 
    return (a < b) ? b : a; 
} 
int getBalance_AVLTree(no_avl *n){ 
    return (n == NULL) ? 0 : (getHeight_AVLTree(n->left) - getHeight_AVLTree(n->right)); 
} 
no_avl* createEl_AVLTree(int value){
    no_avl* el = malloc(sizeof(no_avl));
    el->value = value;
    el->height = 1;
    el->left = el->right = NULL;
    return el;
}
no_avl* rightRotate_AVLTree(no_avl *y) { 
    
    // 1. Criando nós temporários

    no_avl *x = y->left; 
    no_avl *T2 = x->right; 
    
    // 2. Realizando a rotação

    x->right = y; 
    y->left = T2; 
  
    // 3. Alternado as alturas

    y->height = getMax_AVLTree(getHeight_AVLTree(y->left), getHeight_AVLTree(y->right)) + 1; 
    x->height = getMax_AVLTree(getHeight_AVLTree(x->left), getHeight_AVLTree(x->right)) + 1; 
  
    return x; 
} 
  
no_avl* leftRotate_AVLTree(no_avl *y) { 
    
    // 1. Criando nós temporários

    no_avl *x = y->right; 
    no_avl *T2 = x->left; 
  
    // 2. Realizando a rotação

    x->left = y; 
    y->right = T2; 
    
    // 3. Alternado as alturas

    y->height = getMax_AVLTree(getHeight_AVLTree(y->left), getHeight_AVLTree(y->right)) + 1; 
    x->height = getMax_AVLTree(getHeight_AVLTree(x->left), getHeight_AVLTree(x->right)) + 1; 

    return x; 
} 
no_avl* addEl_AVLTree(no_avl* root, int value) { 

    // 1. Procurando o local onde o novo nó deve ser inserido

    if (root == NULL) return(createEl_AVLTree(value)); 
    if (value < root->value) root->left  = addEl_AVLTree(root->left, value); 
    else if (value > root->value) root->right = addEl_AVLTree(root->right, value); 
    else return root; 

    // 2. Modificando a altura do nó

    root->height = 1 + getMax_AVLTree(getHeight_AVLTree(root->left), getHeight_AVLTree(root->right)); 
    
    // 3. Calculando o balanceamento

    int balance = getBalance_AVLTree(root); 

    // 4. Aplicando um dos quatro tipos de rotação caso necessário

    if (balance > 1 && value < root->left->value) return rightRotate_AVLTree(root); 
    if (balance < -1 && value > root->right->value) return leftRotate_AVLTree(root); 
    if (balance > 1 && value > root->left->value){ 
        root->left =  leftRotate_AVLTree(root->left); 
        return rightRotate_AVLTree(root); 
    } 
    if (balance < -1 && value < root->right->value){ 
        root->right = rightRotate_AVLTree(root->right); 
        return leftRotate_AVLTree(root); 
    } 

    return root; 
}
no_avl* removeEl_AVLTree(no_avl* root, int value) {
    
    // 1. Procurando o local onde o nó está e solicitando sua remoção.

    if (root == NULL) return root;
    if (value < root->value) root->left = removeEl_AVLTree(root->left, value);
    else if (value > root->value) root->right = removeEl_AVLTree(root->right, value);
    else root = removeRoot_AVLTree(root);

    // 2. Retorna NULL caso o nó removido seja o último nó da árvore.

    if (root == NULL) return root;

    // 3. Modificando a altura do nó

    root->height = 1 + getMax_AVLTree(getHeight_AVLTree(root->left), getHeight_AVLTree(root->right));

    // 4. Calculando o balanceamento

    int balance = getBalance_AVLTree(root);

    // 5. Aplicando um dos quatro tipos de rotação caso necessário

    if (balance > 1 && getBalance_AVLTree(root->left) >= 0) return rightRotate_AVLTree(root);
    if (balance < -1 && getBalance_AVLTree(root->right) <= 0) return leftRotate_AVLTree(root);
    if (balance > 1 && getBalance_AVLTree(root->left) < 0){
        root->left = leftRotate_AVLTree(root->left);
        return rightRotate_AVLTree(root);
    }
    if (balance < -1 && getBalance_AVLTree(root->right) > 0){
        root->right = rightRotate_AVLTree(root->right);
        return leftRotate_AVLTree(root);
    }

    return root;
}
no_avl* removeRoot_AVLTree(no_avl* root){

    // Cuida dos quatro possíveis casos relacionados com remoção de um nó.
    
    no_avl* newRoot = NULL;
    if(root->left == NULL){
        newRoot = root->right;
        free(root);
        return newRoot;
    }
    if(root->left->right == NULL){
        newRoot = root->left;
        newRoot->right = root->right;
        free(root);
        return newRoot;
    }
    no_avl* parent = root;
    newRoot = root->left;
    while (newRoot->right != NULL){
        parent = newRoot;
        newRoot = newRoot->right;
    }
    if (parent != root)
        parent->right = newRoot->left;
    
    newRoot->left = root->left;
    newRoot->right = root->right;
    free(root);
    return newRoot;
}

void freeMemory_AVLTree(no_avl* root){
    if(root){
        freeMemory_AVLTree(root->left);
        freeMemory_AVLTree(root->right);
        free(root);
    }
}
