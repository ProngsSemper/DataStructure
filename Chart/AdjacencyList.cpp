//
// Created by Prongs on 2021/8/19.
//
//图中顶点数目的最大值
#define MaxVertexNum 100
//边表结点
typedef struct ArcNode {
    //该弧所指向的顶点的位置
    int adjvex;
    //指向下一条弧的指针
    struct ArcNode *next;
} ArcNode;

//顶点表结点
typedef struct VNode {
    //顶点表信息
    char data;
    //指向第一条依附该顶点的弧的指针
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct {
    //邻接表
    AdjList vertices;
    //图的定点数和弧数
    int vexnum, arcnum;
} ALGraph;
