//
// Created by Prongs on 2021/7/24.
//
#include <cstdlib>
#include <cstdio>

typedef struct BiNode {
    int data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree tree) {
    printf("%d", tree->data);
}

void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void MidOrder(BiTree T){
    if (T != NULL) {
        MidOrder(T->lchild);
        visit(T);
        MidOrder(T->rchild);
    }
}

void LastOrder(BiTree T){
    if (T != NULL) {
        LastOrder(T->lchild);
        visit(T);
        LastOrder(T->rchild);
    }
}

