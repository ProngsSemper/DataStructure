//
// Created by Prongs on 2021/7/30.
//
#include <cstdlib>

typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL;

void visit(ThreadTree pNode);

//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree t) {
    if (t != NULL) {
        InThread(t->lchild);
        visit(t);
        InThread(t->rchild);
    }
}

void visit(ThreadNode *q) {
    //左子树为空建立前驱线索
    if (q->lchild == NULL) {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        //建立前驱结点的后继线索
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//中序线索化二叉树t
void CreateInThread(ThreadTree t) {
    //初始化为空
    pre = NULL;
    //非空才能遍历
    if (t != NULL) {
        InThread(t);
        if (pre->rchild == NULL) {
            //处理遍历的最后一个结点
            pre->rtag = 1;
        }
    }
}

void PreThread(ThreadTree t) {
    if (t != NULL) {
        visit(t);
        //lchild不是前驱线索才线索化，否则会造成死循环
        if (t->ltag == 0) {
            PreThread(t->lchild);
        }
        PreThread(t->rchild);
    }
}

//先序线索化二叉树t
void CreatePreThread(ThreadTree t) {
    //初始化为空
    pre = NULL;
    //非空才能遍历
    if (t != NULL) {
        PreThread(t);
        if (pre->rchild == NULL) {
            //处理遍历的最后一个结点
            pre->rtag = 1;
        }
    }
}

void PostThread(ThreadTree t) {
    if (t != NULL) {
        PostThread(t->lchild);
        PostThread(t->rchild);
        visit(t);
    }
}

//后序线索化二叉树t
void CreatePostThread(ThreadTree t) {
    //初始化为空
    pre = NULL;
    //非空才能遍历
    if (t != NULL) {
        PostThread(t);
        if (pre->rchild == NULL) {
            //处理遍历的最后一个结点
            pre->rtag = 1;
        }
    }
}


