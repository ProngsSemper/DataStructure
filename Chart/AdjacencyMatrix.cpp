//
// Created by Prongs on 2021/8/19.
//
//顶点最大数值
#define MaxVertexNum 100
#define INFINITY
//顶点数据类型
typedef char VertexType;
//带权图中边的权值的数据类型
typedef int EdgeType;
typedef struct{
    //顶点表
    VertexType Vex[MaxVertexNum];
    //领接矩阵，表边
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    //图的当前顶点数和弧数
    int vexnum,arcnum;
}MGraph;

bool visited[MaxVertexNum];

void BFSTraverse(MGraph g){
    for (int i=0;i<g.vexnum;i++){
        visited[i]= false;
    }

}