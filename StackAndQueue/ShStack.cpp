//
// Created by Prongs on 2021/7/6.
//
//共享栈
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top0;
    int top1;
}ShStack;

//初始化
void initShStack(ShStack &shStack){
    //一个在最上面一个在最下面
    shStack.top0 = -1;
    shStack.top1 = MaxSize;
}
