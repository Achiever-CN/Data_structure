#ifndef FIG_H_
#define FIG_H_

#include <iostream>
#include <string>
using namespace std;

typedef string VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INEINITY 65535


//Lead matrix
typedef struct
{
        VertexType vexs[MAXVEX];        //vertex table
        EdgeType arc[MAXVEX][MAXVEX];   //side table
        int numVertexes, numEdges;      //the num of vertex and side
}MGraph;


void CreatMGraph (MGraph * G)
{
        int i ,j , k, w;
        cout << "请输入顶点数和边数" << endl;
        cin >> G->numVertexes >> G->numEdges;
        for(i = 0; i < G->numVertexes; i++)             //the name of vexs
                cin >> G->vexs[i];
        for(i = 0; i < G->numVertexes; i++)             //Initialized to infinity
                for(j = 0; j < G->numVertexes; j++)
                        G->arc[i][j] = INEINITY;
        for(k = 0; k < G->numVertexes; k++)
        {
                cout << "please input the x and y of side and the power" << endl;
                cin >> i >> j >> w;
                G->arc[i][j] = w;
                G->arc[j][i] = G->arc[i][j];            //get the the matrix
        }
}




typedef struct EdgNode                  //the srtuct of edg
{
        int adject;                     //the next one
        EdgeType weight;
        struct EdgNode *next;
}EdgeNode;


typedef struct VertexNode               //the struct of Verts
{
        VertexType data;
        EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct                          
{
        AdjList adjList;
        int numVertexes, numEdges;
}GraphAdjList;

void CreatALGraph(GraphAdjList *G)
{
        int i, j, k;
        EdgeNode *e;
        cout << "please input the num of verts and edg" << endl;
        for(i = 0; i < G->numVertexes; i++)
        {
                cin >> G->adjList[i].data;
                G->adjList[i].firstedge = NULL;
        }


        for(k = 0; k < G->numEdges; k++)
        {
                cout << "Please input the x y" << endl;
                cin >> i >> j;
                e = new EdgeNode;
                e->adject = j;
                e->next = G->adjList[i].firstedge;
                G->adjList[i].firstedge = e;
                e = new EdgeNode;
                e->adject = i;
                e->next = G->adjList[j].firstedge;
                G->adjList[j].firstedge = e;
        }
};










#endif