//
// Created by Prongs on 2021/6/22.
//

#include <stdlib.h>

typedef struct DNode {
    int data;
    //指针指向下一个节点
    struct DNode *next, *prior;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &l) {
    l = (DNode *) malloc(sizeof(DNode));
    if (l == NULL) return false;
    l->next = NULL;
    l->prior = NULL;
    return true;
}

//在p节点的下一个节点插入
bool insertNextDNode(DNode *p, DNode *q) {
    if (p == NULL || q == NULL)return false;
    //将要插入的q节点的后继节点指向p的后继节点
    q->next = p->next;
    //如果p的后继节点不是NULL，则另p的后继节点的前驱节点指向q
    if (p->next != NULL) {
        p->next->prior = q;
    }
    q->prior = p;
    p->next = q;
    return true;
}

//删除p后的节点
bool deleteNextDNode(DNode *p) {
    //首先判断p这个节点是不是NULL
    if (p == NULL)return false;
    DNode *q = p->next;
    //判断p后面的节点是不是NULL
    if (q == NULL)return false;
    //让p的后继节点指向原来下一个的下一个
    p->next = q->next;
    //如果原来p的后继节点的下一个不是NULL则使其指向P
    if (q->next != NULL)q->next->prior = p;
    //释放节点空间
    free(q);
    return true;
}

void DestoryDNodeList(DLinkList l) {
    if (l->next != NULL)deleteNextDNode(l);
    //释放头节点
    free(l);
    //头指针指向NULL
    l = NULL;
}

void testDLinkList() {
    DLinkList L;
    InitDLinkList(L);
}