#include <stdlib.h>

#define InitSize 10

typedef struct {
    int *data;
    int MaxSize;
    int length;
} SqList;

//按序查找
int GetElem(SqList L, int i) {
    return L.data[i - 1];
}
//按值查找
int LocateElem(SqList L, int i) {
    for (int j = 0; j < L.length; j++) {
        if (L.data[j] == i) {
            return j + 1;
        }
    }
    return -1;
}

