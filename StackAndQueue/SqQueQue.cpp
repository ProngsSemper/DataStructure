//
// Created by Prongs on 2021/7/9.
//

#define MaxSize 10
typedef struct {
    //可容纳十个数的数组，下标0~9
    int data[MaxSize];
    int front, rear;
} SqQueQue;

typedef struct {
    int data[MaxSize];
    int front, rear;
    //每次出队入队记录队列大小变化
    int size;
} SqQueQueSize;

typedef struct {
    int data[MaxSize];
    int front, rear;
    //每次记录最近进行的是删除/插入
    int tag;
} SqQueQueTag;

bool isEmpty(SqQueQue que){
    if(que.rear == que.front)
        return true;
    else
        return false;
}

bool Enque(SqQueQue &que,int x){
    //判满（牺牲了一个存储位置），用循环列表的方式，如果尾指针的下一个指针是头指针则为满队列
    if(((que.rear+1)%MaxSize)==que.front){
        return false;
    }
    que.data[que.rear]=x;
    //que.rear+=1; 这样子写如果有元素出队，尾指针不会动，前面的空间就直接当没有了

    //模运算的话 没超过最大长度maxsize那rear就会等于rear+1，超过一个rear=1，超过两个rear=2（把尾指针指回前面的位置，让前面的位置还能放元素）
    que.rear=(que.rear+1)%MaxSize;
    return true;
}

bool deQueQue(SqQueQue &que,int &x){
    if(isEmpty(que)){
        return false;
    }
    x=que.data[que.front];
    que.front=(que.front+1)%MaxSize;
    return true;
}

bool getHead(SqQueQue que,int &x){
    if(isEmpty(que)){
        return false;
    }
    x=que.data[que.front];
    return true;
}

void initQueQue(SqQueQue que) {
    //头尾指针指向0
    que.front = que.rear = 0;
}