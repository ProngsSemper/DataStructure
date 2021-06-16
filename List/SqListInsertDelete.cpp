#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//下面两个函数都是让使用者不用管数组从0开始，按照正常思维从1开始，程序自动判断位序和数组下标
bool Insert(SqList &L, int t, int e) {
    //插入位置小于第一个或者大于表尾后一个（不能跳着插）
    if (t < 1 || t > L.length + 1)
        return false;
    //表满
    if (L.length >= MaxSize)
        return false;
    //后移元素，最后一个会移到比原来表长+1的位置，所以直接用length作为数组的下标没问题
    for (int i = L.length; i >= t; i--) {
        L.data[i] = L.data[i - 1];
    }
    //插入
    L.data[t - 1] = e;
    //表长度+1
    L.length++;
    return true;
}

bool Delete(SqList &L, int t, int &e) {
    //判断t是否大于或小于表长度，此处不能大于L.length+1因为是删除，不能删除比表长度还大的没有东西的位置
    if (t < 1 || t > L.length) {
        return false;
    }
    //把这个要删除的元素赋值给e带回，可以显示被删的元素是啥
    e = L.data[t - 1];
    //前移元素
    for (int i = t; i < L.length; i++) {
        L.data[t - 1] = L.data[t];
    }
    L.length--;
    return true;
}

int main(){

};

