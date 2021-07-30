//
// Created by Prongs on 2021/7/30.
//
#include <cstdlib>

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTNode *BST_Search(BSTree t, int key) {
    while (t != NULL && key != t->key) {
        if (key < t->key) {
            t = t->rchild;
        } else {
            t = t->lchild;
        }
    }
    return t;
}

BSTNode *BSTSearch(BSTree t, int key) {
    if (t == NULL) return NULL;
    if (key == t->key) {
        return t;
    } else if (key < t->key) {
        return BSTSearch(t->lchild, key);
    } else {
        return BSTSearch(t->rchild, key);
    }
}

int BST_Insert(BSTree &t, int k) {
    if (t == NULL) {
        t = (BSTree) malloc(sizeof(BSTNode));
        t->key = k;
        t->lchild = t->rchild = NULL;
        return 1;
    } else if (k == t->key) {
        return 0;
    } else if (k < t->key) {
        return BST_Insert(t->lchild, k);
    } else
        return BST_Insert(t->rchild, k);
}

void CreateBst(BSTree &t, int str[], int n) {
    t = NULL;
    int i = 0;
    while (i < n) {
        BST_Insert(t, str[i]);
        i++;
    }
}