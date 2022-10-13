#ifndef LINEAR_GRAPH_H_
#define LINEAR_GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define n 100
//utf�?8
//线性图，利用一个固定最大长度的数组来储存顶点，并储存顶点数和总边�??
//对于无向图，只需要记录哪两个顶点之间有联�??,利用arc来储存邻接表

struct linear_graph
{
        vector<string> list;            //list储存各个顶点
        vector<vector<int>> arc;        //arc用来储存紧接表，及各个顶点之间的关系
        int num_vertexes, num_edgs;     //num_vertexes是顶点数�? num_edgs是边的总数
};




//此类是无向图
class Linear_graph_without_direction
{
        public:
                Linear_graph_without_direction(int n1, int n2);
                ~Linear_graph_without_direction();
        private:
                linear_graph graph;
        friend void Dfstraverse(Linear_graph_without_direction &G);
        friend void Dfs(Linear_graph_without_direction &G, int i, vector<int>& visited);
        friend void Bfs(Linear_graph_without_direction &G);
        friend void prim (Linear_graph_without_direction& G);
        friend void kruskal(Linear_graph_without_direction& G);
};


Linear_graph_without_direction:: Linear_graph_without_direction(int n1,int n2)
{
        graph.num_vertexes = n1;
        graph.num_edgs = n2;
        
        //重新设置arc数组的大小，并设置初始值为0

        graph.arc.resize(n1);
        for(int i = 0; i < graph.arc.size(); i++)
        {
                graph.arc[i].resize(n1);
                graph.arc[i].assign(n1,0);
        }

        //依次输入顶点

        string temp;
        for(int i = 0; i < graph.num_vertexes; i++)
        {
                cout << "Please input the vertexe one by one" << endl;
                cin >> temp;
                graph.list.push_back(temp);
        }


        //以此输入各个边的顶点，此类是无向图，这里通过匹配字符串来获取下标，对arc数组进行修改

        for(int i = 0; i < graph.num_edgs; i ++)
        {
                cout << "Please enter the vertices on both sides of the line" << endl;
                string t1, t2;
                int temp;
                cin >> t1 >> t2 >> temp;
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
                        graph.arc[x][y] = temp;
                        graph.arc[y][x] = temp;
                }

        }
}


Linear_graph_without_direction::  ~Linear_graph_without_direction()
{
        //循环打印arc数组

        for(int i = 0; i < graph.list.size(); i++)
        {
                for(int j = 0; j < graph.arc[0].size(); j++)
                {
                        cout << graph.arc[i][j] << " ";
                }
                cout << endl;
        }
}

//调用DFS深度搜索遍历，一条路走到黑，再回头
void Dfs(Linear_graph_without_direction &G, int i, vector<int>& visited)
{
        int j; 
        visited[i] = 1;                                         //将该点标记为遍历�?
        cout << G.graph.list[i] << ' ';                         //打印该顶�?
        for(j = 0; j < G.graph.num_vertexes; j++)
                if(G.graph.arc[i][j] != 0 && !visited[j])       //遍历与list[i]有联系的未遍历过的顶�?
                        Dfs(G,j,visited);
};


void Dfstraverse(Linear_graph_without_direction &G)
{
        vector<int> visited(G.graph.num_vertexes, 0);
        for(int i= 0; i < G.graph.num_vertexes; i++)
        {
                if(!visited[i])
                        Dfs(G,i,visited);
        }
        cout << endl;
}


//先第一层，再第二层，再下一层，利用队列，入队出队
void Bfs(Linear_graph_without_direction &G)
{
        vector<int> visited(G.graph.num_vertexes, 0);
        vector<int> queue;
        visited[0] = 1;
        cout << "v0" << ' ';
        for(int i = 0; i < G.graph.num_vertexes; i++)
        {
                if(G.graph.arc[0][i] != 0)
                {
                        queue.push_back(i);
                        visited[i] = 1;
                }
        }

        while(queue.size())
        {
                // cout << "queue.size() = "<< queue.size() << endl;
                int temp = queue.front();
                queue.erase(queue.begin(),queue.begin()+1);
                cout << G.graph.list[temp] << ' ';
                visited[temp] = 1;

                for(int i = 0; i < G.graph.num_vertexes; i++)
                {
                        if(G.graph.arc[temp][i] != 0 && visited[i] == 0)
                        {
                                queue.push_back(i);
                                visited[i] = 1;
                        }
                }

        }

        cout << endl;

}

//所有已被选择的点和未被选择的点组成两个集合，找到两个集合之间的最小值，并记录下最新的被选择点，形成新的两个集合，
//反复即可遍历所有的顶点
void prim (Linear_graph_without_direction& G)
{
        vector<int> selected(G.graph.num_vertexes, 0);
        vector<int> lowcost(G.graph.num_vertexes, INT_MAX);
        selected[0] = 1;
        int num_selected = 1;
        cout << G.graph.list[0];
        int i = 0, j;
        while(num_selected != G.graph.num_vertexes)
        {
                for(j = 0; j < G.graph.num_vertexes; j++)
                {
                        if(G.graph.arc[i][j] != 0 && G.graph.arc[i][j] < lowcost[j] && selected[j] != 1)
                        {
                                lowcost[j] = G.graph.arc[i][j];
                        }
                }
                int min = INT_MAX, temp_j;
                for(j = 0; j < G.graph.num_vertexes; j++)
                {
                        if(lowcost[j] < min)
                        {
                                min = lowcost[j];
                                temp_j = j;
                        }
                }

                selected[temp_j] = 1;
                lowcost[temp_j] = INT_MAX;
                num_selected ++;
                i = temp_j;
                cout <<  "->" << G.graph.list[i];                

        }
        cout << endl;

}


int find_num(int num, vector<int>& l)
{       
        if(! (l.size() > 0))
                return 1;

        for(int i = 0; i < l.size(); i ++)
        {
                if(num == l[i])
                        return 0;
        }
        return 1;
}
void kruskal(Linear_graph_without_direction& G)
{
        vector<int> begin(G.graph.num_edgs, 0);
        vector<int> end(G.graph.num_edgs, 0);
        vector<int> wight(G.graph.num_edgs, 0);
        vector<vector<int>> temp_arc = G.graph.arc;
        for(int i = 0; i < G.graph.num_edgs; i++)
        {
                int min = INT_MAX;
                int temp_j = 0, temp_k = 0;
                for(int j = 0; j < G.graph.num_vertexes; j++)
                {
                        for(int k = j; k < G.graph.num_vertexes; k++)
                        {
                                if(temp_arc[j][k] <= min && temp_arc[j][k] != 0)
                                {
                                        min = temp_arc[j][k];
                                        temp_j = j;
                                        temp_k = k;
                                }
                        }
                }
                begin[i] = temp_j;
                end[i] = temp_k;
                wight[i] = min;
                temp_arc[temp_j][temp_k] = INT_MAX;
                // cout << begin[i] << " > " << end[i] << " = " << wight[i] << endl;
        }

        
        vector<int> selected;
        int num_edgs = 0;
        for(int i = 0; num_edgs != G.graph.num_vertexes -1 && i < G.graph.num_edgs; i++)
        {
                if(find_num(begin[i], selected) && find_num(end[i], selected))
                {
                        selected.push_back(begin[i]);
                        selected.push_back(end[i]);
                        cout << begin[i] << " > " << end[i] << " = " << wight[i] << endl;
                        num_edgs ++;
                }
        }
        

}













//此类是加权有向图
class Linear_graph_wight
{
        public:
                Linear_graph_wight(int n1, int n2);
                ~Linear_graph_wight();
        private:
                linear_graph graph;
        friend void Dfstraverse(Linear_graph_wight &G);
        friend void Dfs(Linear_graph_wight &G, int i, vector<int>& visited);
        friend void Bfs(Linear_graph_wight &G);
        friend void prim (Linear_graph_wight& G);
};


Linear_graph_wight :: Linear_graph_wight(int n1, int n2)
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

        //此类是加权有向图
        for(int i = 0; i < graph.num_edgs; i ++)
        {
                cout << "Please enter the vertices on both sides of the line and the wight" << endl;
                string t1, t2;
                int wight;
                cin >> t1 >> t2 >> wight;
                int x = -1, y = -1;
                for(int j = 0; j < graph.num_vertexes; j++)
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
                        graph.arc[x][y] = wight;
                }

        }
};


Linear_graph_wight::  ~Linear_graph_wight()
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


//调用DFS深度搜索遍历，一条路走到黑，再回头
void Dfs(Linear_graph_wight &G, int i, vector<int>& visited)
{
        int j; 
        visited[i] = 1;                                         //将该点标记为遍历�?
        cout << G.graph.list[i] << ' ';                         //打印该顶�?
        for(j = 0; j < G.graph.num_vertexes; j++)
                if(G.graph.arc[i][j] != 0 && !visited[j])       //遍历与list[i]有联系的未遍历过的顶�?
                        Dfs(G,j,visited);
};


void Dfstraverse(Linear_graph_wight &G)
{
        vector<int> visited(G.graph.num_vertexes, 0);           //对visited数组初始化为0
        int i;
        for(i = 0; i < G.graph.num_vertexes; i++)
        {
                if(!visited[i])                                 //如果i对应的顶点未被遍�?
                        Dfs(G, i, visited);
        }
        cout << endl;
};


//先第一层，再第二层，再下一层，利用队列，入队出队
void Bfs(Linear_graph_wight &G)
{
        vector<int> visited(G.graph.num_vertexes, 0);
        vector<int> queue;
        visited[0] = 1;
        cout << "v0" << ' ';
        for(int i = 0; i < G.graph.num_vertexes; i++)
        {
                if(G.graph.arc[0][i] != 0)
                {
                        queue.push_back(i);
                        visited[i] = 1;
                }
        }

        while(queue.size())
        {
                // cout << "queue.size() = "<< queue.size() << endl;
                int temp = queue.front();
                queue.erase(queue.begin(),queue.begin()+1);
                cout << G.graph.list[temp] << ' ';
                visited[temp] = 1;

                for(int i = 0; i < G.graph.num_vertexes; i++)
                {
                        if(G.graph.arc[temp][i] != 0 && visited[i] == 0)
                        {
                                queue.push_back(i);
                                visited[i] = 1;
                        }
                }

        }

        cout << endl;

}



//所有已被选择的点和未被选择的点组成两个集合，找到两个集合之间的最小值，并记录下最新的被选择点，形成新的两个集合，
//反复即可遍历所有的顶点
void prim (Linear_graph_wight& G)
{
        vector<int> selected(G.graph.num_vertexes, 0);
        vector<int> lowcost(G.graph.num_vertexes, INT_MAX);
        selected[0] = 1;
        int num_selected = 1;
        cout << G.graph.list[0] << ' ';
        int i = 0, j;
        while(num_selected != G.graph.num_vertexes)
        {
                for(j = 0; j < G.graph.num_vertexes; j++)
                {
                        if(G.graph.arc[i][j] != 0 && G.graph.arc[i][j] < lowcost[j] && selected[j] != 1)
                        {
                                lowcost[j] = G.graph.arc[i][j];
                        }
                }
                int min = INT_MAX, temp_j;
                for(j = 0; j < G.graph.num_vertexes; j++)
                {
                        if(lowcost[j] < min)
                        {
                                min = lowcost[j];
                                temp_j = j;
                        }
                }

                selected[temp_j] = 1;
                lowcost[temp_j] = INT_MAX;
                num_selected ++;
                i = temp_j;
                cout << G.graph.list[i] << ' ';                

        }
        cout << endl;

}






#endif