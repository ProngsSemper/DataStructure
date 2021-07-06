//
// Created by Prongs on 2021/7/6.
//
#define MaxSize 10 //定义栈中元素的最大个数

//顺序栈
typedef struct {
    int data[MaxSize]; //静态数组存放栈中元素
    int top; //栈顶指针
} SqStack;

void initSqStack(SqStack &ss) {
    ss.top = -1; //初始化栈顶指针
}

bool isEmpty(SqStack ss) {
    if (ss.top == -1) {
        return true;
    } else {
        return false;
    }
}

//入栈
bool push(SqStack &ss, int x) {
    if (ss.top == MaxSize - 1) {
        return false; //栈满
    }
    ss.top = ss.top + 1; //移动栈顶指针，例如首次加入就从-1变成1了（栈顶指针也是数组下标）
    ss.data[ss.top] = x; //入栈
    return true;
}

//出栈
bool pop(SqStack &ss, int &x) {
    //栈空报错
    if (ss.top == -1) {
        return false;
    }
    //把栈顶元素赋给x并让其带回（注意这里是top--，给了x再把栈顶指针下一一个）
    x = ss.data[ss.top--];
    return true;
}

//读栈顶元素
bool getTop(SqStack &ss, int &x) {
    //栈空报错
    if (ss.top == -1) {
        return false;
    }
    x = ss.data[ss.top];
    return true;
}

void testStack() {
    SqStack ss;
}

