#ifndef LINEAR_GRAPH_H_
#define LINEAR_GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define n 100

//线性图，利用一个固定最大长度的数组来储存顶点，并储存顶点数和总边数
//对于无向图，只需要记录哪两个顶点之间有联系,利用arc来储存邻接表

struct linear_graph
{
        vector<string> list;
        vector<vector<int>> arc;
        int num_vertexes, num_edgs;
};


class Linear_graph
{
        public:
                Linear_graph(int n1, int n2);
                ~Linear_graph();
        private:
                linear_graph graph;
};

Linear_graph:: Linear_graph(int n1,int n2)
{
        graph.num_vertexes = n1;
        graph.num_edgs = n2;
        
        graph.arc.resize(n1);
        for(int i = 0; i < graph.arc.size(); i++)
        {
                graph.arc[i].resize(n1);
                graph.arc[i].assign(n1,0);
        }

        string temp;

        for(int i = 0; i < graph.num_vertexes; i++)
        {
                cout << "Please input the vertexe one by one" << endl;
                cin >> temp;
                graph.list.push_back(temp);
        }


        for(int i = 0; i < graph.num_edgs; i ++)
        {
                cout << "Please enter the vertices on both sides of the line" << endl;
                string t1, t2;
                cin >> t1 >> t2;
                int x = -1, y = -1;
                for(int j = 0; j < graph.list.size(); j++)
                {
                        if(graph.list[j] == t1)
                                x = j;
                        if(graph.list[j] == t2)
                                y = j;
                        if(x != -1 && y != -1) 
                                break;
                }
                if(x == -1 || y== -1)
                {
                         cout << "input error" << endl;
                         break;
                }
                else
                {
                        graph.arc[x][y] = 1;
                        graph.arc[y][x] = 1;
                }

        }
}

Linear_graph::  ~Linear_graph()
{
        for(int i = 0; i < graph.list.size(); i++)
        {
                for(int j = 0; j < graph.arc[0].size(); j++)
                {
                        cout << graph.arc[i][j] << " ";
                }
                cout << endl;
        }
}



#endif