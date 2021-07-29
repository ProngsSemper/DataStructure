//
// Created by Prongs on 2021/7/29.
//
#include <cstdlib>
#include <cstdio>

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct ThreadNode {
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(ThreadNode *node) {
    printf("%d", node);
}

ThreadNode *Firstnode(ThreadNode *p) {
    while (p->ltag == 0)p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p) {
    if (p->rtag == 0) {
        return Firstnode(p->rchild);
    } else {
        return p->rchild;
    }
}

void Inorder(ThreadNode *t) {
    for (ThreadNode *p = Firstnode(t); p != NULL; p = Nextnode(p)) {
        visit(p);
    }
}

ThreadNode *Lastnode(ThreadNode *p) {
    while (p->rtag == 0)p = p->rchild;
    return p;
}

ThreadNode *Prenode(ThreadNode *p) {
    if (p->ltag == 0) {
        return Firstnode(p->lchild);
    } else {
        return p->lchild;
    }
}

void Revorder(ThreadNode *t) {
    for (ThreadNode *p = Lastnode(t); p != NULL; p = Prenode(p)) {
        visit(p);
    }
}

