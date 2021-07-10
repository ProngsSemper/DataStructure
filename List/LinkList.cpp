//
// Created by Prongs on 2021/6/14.
//

#include <cstdlib>
#include <cstdio>

typedef struct LNode {
    int data;
    //指针指向下一个节点
    struct LNode *next;
} LNode, *LinkList;

bool Init(LinkList &L) {
    L = NULL;
    return true;
}

//循环链表
bool initCycleList(LinkList &l) {
    l = (LNode *) malloc(sizeof(LNode));
    if (l == NULL)return false;
    l->next = l;
    return true;
}

bool EmptyList(LinkList L) {
    return L == NULL;
}

bool InitWithHead(LinkList &L) {
    //分配头结点
    L = (LNode *) malloc((sizeof(LNode)));
    //内存不足分配失败
    if (L == NULL) return false;
    //头结点后暂时没有节点
    L->next = NULL;
    return true;
}

bool emptyWithHead(LinkList L) {
    return L->next == NULL;
}

bool insertAfterNode(LNode *p, int e) {
    if (p == NULL)return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    //内存分配失败
    if (s == NULL)return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool insertPriorNode(LNode *p, int e) {
    if (p == NULL)return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)return false;
    s->data = p->data;
    p->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//按位序删除指定节点（带头）
bool deleteListWithHead(LinkList &L, int i, int &e) {
    if (i < 1)return false;
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)return false;
    if (p->next == NULL)return false;
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

bool deleteNode(LNode *p) {
    if (p == NULL)return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//按位查找
LNode *GetElem(LinkList L, int i) {
    if (i < 0)return NULL;
    int j = 0;
    LNode *p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

LinkList InsertTail(LinkList &l) {
    int x;
    l = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = l;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return l;
}

LinkList headInsert(LinkList &l) {
    LNode *s;
    int x;
    l->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        scanf("%d", &x);
    }
    return l;
}

bool insertListWithHead(LinkList &L, int i, int e) {
    //位置不合法
    if (i < 1)return false;
    //创建一个节点让他指向当前扫描的节点
    LNode *p = GetElem(L, i - 1);

    /**
    //从头结点开始
    int j = 0;
    //扫描要插入的位置的前一个位置
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    **/

    insertAfterNode(p, e);
    /**
    //位置不合法
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    //这两行不能替换顺序
    s->next = p->next;
    p->next = s;
    return true;
     **/
}

bool listInsertWithoutHead(LinkList &L, int i, int e) {
    if (i < 1)return false;
    //不带头结点在第一个位置插入需要特殊操作
    if (i == 1) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        p->data = e;
        p->next = L;
        L = p;
    }
    LNode *p = GetElem(L, i - 1);

    /**
    //从头结点开始
    int j = 0;
    //扫描要插入的位置的前一个位置
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    **/

    insertAfterNode(p, e);

    /**
    //位置不合法
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    //这两行不能替换顺序
    s->next = p->next;
    p->next = s;
    return true;
     **/
}


void test() {
    LinkList L;
    Init(L);

};

int main() {
    LinkList l;
    InsertTail(l);
    while (l != NULL) {
        printf("%d", l->data);
        l = l->next;
    }
}
