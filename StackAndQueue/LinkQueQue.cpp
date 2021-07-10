//
// Created by Prongs on 2021/7/10.
//
#include <cstdlib>
#include <cstdio>

typedef struct LinkNode {
    int data;
    LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueQue;

void initWithHead(LinkQueQue &que) {
    que.front = que.rear = (LinkNode *) malloc(sizeof(LinkNode));
    que.front->next = NULL;
}

bool isEmptyWithHead(LinkQueQue que) {
    if (que.front == que.rear) {
        return true;
    }
    return false;
}

void initNoHead(LinkQueQue &que) {
    que.front = NULL;
    que.rear = NULL;
}

bool isEmptyNoHead(LinkQueQue que) {
    if (que.front == NULL) {
        return true;
    }
    return false;
}

void enQueQueWithHead(LinkQueQue &que, int x) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    //新节点插到表尾后
    que.rear->next = p;
    //修改尾指针到p
    que.rear = p;
}

void enQueQueNoHead(LinkQueQue &que, int x) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    if (isEmptyNoHead(que)) {
        que.front = p;
        que.rear = p;
    } else {
        que.rear->next = p;
        que.rear = p;
    }
}

bool delWithHead(LinkQueQue &que, int &x) {
    if (isEmptyWithHead(que)) {
        return false;
    } else {
        LinkNode *s = que.front->next;
        x = s->data;
        que.front = s->next;
        if (que.rear == s) {
            que.rear = que.front;
        }
        free(s);
        return true;
    }
}

bool delNoHead(LinkQueQue &que, int &x) {
    if (isEmptyNoHead(que)) {
        return false;
    } else {
        LinkNode *p = que.front;
        x = p->data;
        que.front = p->next;
        if (que.front == que.rear) {
            que.front = NULL;
            que.rear = NULL;
        }
        free(p);
        return true;
    }

}


