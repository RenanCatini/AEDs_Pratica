#include <stdio.h>
#include <stdlib.h>
#include "defaultSearchTree.h"

no_def* createEl_DefTree(int value){
    no_def* el = malloc(sizeof(no_def));
    el->value = value;
    el->left = el->right = NULL;
    return el;
}
no_def* searchEl_DefTree(no_def* root, no_def** rootDad, int value){
    
    // Procurando o local onde o nó está e retornando seu endereço.

    if(root == NULL || root->value == value) return root;
    if(root->value > value){
        *rootDad = root;
        return searchEl_DefTree(root->left, rootDad, value);
    }
    else{
        *rootDad = root;
        return searchEl_DefTree(root->right, rootDad, value);
    }
}
no_def* addEl_DefTree(no_def* root, no_def* el){

    // Procurando o local onde o novo nó deve ser inserido

    if(root == NULL) return el;
    if(root->value > el->value) root->left = addEl_DefTree(root->left, el);
    else root->right = addEl_DefTree(root->right, el); 
    return root;
}
no_def* removeEl_DefTree(no_def* root, int value){
    
    // 1. Procurando o nó a ser removido e seu pai

    no_def* rSearchElDad = NULL;
    no_def* rSearchEl = searchEl_DefTree(root, &rSearchElDad, value);

    // 2. Solicitando a remoção levando em consideração os resultados obtidos
     
    if(rSearchEl){
        if(rSearchElDad){
            if(rSearchElDad->right == rSearchEl)
                rSearchElDad->right = removeRoot_DefTree(rSearchEl);
            else
                rSearchElDad->left = removeRoot_DefTree(rSearchEl);
        }
        else{
            root = removeRoot_DefTree(rSearchEl);
        }
    }
    return root;
}
no_def* removeRoot_DefTree(no_def* root){

    // Cuida dos quatro possíveis casos relacionados com remoção de um nó.

    no_def* newRoot = NULL;
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
    no_def* parent = root;
    newRoot = root->left;
    while (newRoot->right != NULL) {
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

void freeMemory_DefTree(no_def* root){
    if(root){
        freeMemory_DefTree(root->left);
        freeMemory_DefTree(root->right);
        free(root);
    }
}
