#ifndef LINEAR_GRAPH_H_
#define LINEAR_GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define n 100


struct linear_graph
{
        vector<string> list;            
        vector<vector<int>> arc;        
        int num_vertexes, num_edgs;   
};


//Linear_graph_without_direction
#if 1

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
        friend void Dijkstra(string t1, string t2, Linear_graph_without_direction& G);
        friend void floyd(string t1, string t2, Linear_graph_without_direction& G);
};


Linear_graph_without_direction:: Linear_graph_without_direction(int n1,int n2)
{
        graph.num_vertexes = n1;
        graph.num_edgs = n2;
        
        //reset the arc[][],and set the initial value to 0;

        graph.arc.resize(n1);
        for(int i = 0; i < graph.arc.size(); i++)
        {
                graph.arc[i].resize(n1);
                graph.arc[i].assign(n1,0);
        }

        //get vertex

        string temp;
        for(int i = 0; i < graph.num_vertexes; i++)
        {
                cout << "Please input the vertexe one by one" << endl;
                cin >> temp;
                graph.list.push_back(temp);
        }


        //Symmetric matrix

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
        //show the arc
        cout <<   "    ";
        for(int i = 0; i < graph.num_vertexes; i++)
        {
                cout << graph.list[i] << "  ";
        }
        cout << endl;
        for(int i = 0; i < graph.list.size(); i++)
        {
                cout << graph.list[i] << "  ";
                for(int j = 0; j < graph.arc[0].size(); j++)
                {
                        cout << setw(2) << graph.arc[i][j] << "  ";
                }
                cout << endl;
        }
}

//DFS traverse the Linear_graph_without_direction
void Dfs(Linear_graph_without_direction &G, int i, vector<int>& visited)
{
        int j; 
        visited[i] = 1;                                         //mark which one has been print
        cout << G.graph.list[i] << ' ';                         //print the vert
        for(j = 0; j < G.graph.num_vertexes; j++)
                if(G.graph.arc[i][j] != 0 && !visited[j])       //One way to the end and then back
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


//use queue, One floor by one floor
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


//The shortest path between a set of selected points and a set of selected points
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


//Check if an element is in the array
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


//first, all edges are sorted according to weights, and small weighted edges that do not form loops are selected
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
        }

       
        //Detect whether it is looped or not     
        vector<int> selected;
        int num_edgs = 0;
        for(int i = 0; num_edgs != G.graph.num_vertexes -1 && i < G.graph.num_edgs; i++)
        {
                if(find_num(begin[i], selected) || find_num(end[i], selected))
                {
                        selected.push_back(end[i]);
                        cout << begin[i] << " > " << end[i] << " = " << wight[i] << endl;
                        num_edgs ++;
                }
        }
        

}


//Get the shortest path from one vertex to the others
void Dijkstra(string t1, string t2, Linear_graph_without_direction& G)
{
        vector<int> verts(G.graph.num_vertexes,0);
        vector<int> go(G.graph.num_vertexes, INT_MAX);
        vector<int> last(G.graph.num_vertexes, INT_MAX);

        int v_begin = 0, v_end = 4;
        
        verts[v_begin] = 1;
        go[v_begin] = 0;
        last[v_begin] = 0;
        int v_v_begin = v_begin;
        for(int j = 0; j < G.graph.num_vertexes; j++)
        {
                
                for(int i = 0; i < G.graph.num_vertexes; i++)
                {
                        if(G.graph.arc[v_v_begin][i] != 0 && G.graph.arc[v_v_begin][i] + go[v_v_begin] < go[i])
                        {
                                go[i] = G.graph.arc[v_v_begin][i] + go[v_v_begin];
                                last[i] = v_v_begin;
                                
                        }
                }

                int min = INT_MAX;
                for(int i = 0; i < G.graph.num_vertexes; i++)
                {
                        if(go[i] < min && go[i] != 0 && verts[i] == 0)
                        {
                                min = go[i];
                                v_v_begin = i;
                        }
                }
                verts[v_v_begin] = 1;
                v_begin = v_v_begin;


        }


}



void floyd(string t1, string t2, Linear_graph_without_direction& G)
{
        vector<vector<int>> arc(G.graph.num_vertexes);
        vector<vector<int>> path(G.graph.num_vertexes);
        for(int i = 0; i < G.graph.num_vertexes; i++)
        {
                arc[i] = G.graph.arc[i];
                // for(int j = 0; j < G.graph.num_vertexes; j++)
                // {
                //         if(i != j)
                //                 if(arc[i][j] == 0)
                //                         arc[i][j] = INT_MAX;
                // }
                path[i].resize(G.graph.num_vertexes, -1);
        }

        vector<vector<int>> vertex_pairs(G.graph.num_vertexes * (G.graph.num_vertexes-1));
        int a = 0, b = 1;
        for(int i = 0; i < vertex_pairs.size(); i ++)
        {
                vertex_pairs[i].resize(2);
                if(b > G.graph.num_vertexes - 1)
                {
                        a++, b = 0;
                }   
                if(a == b)
                        b += 1;
                vertex_pairs[i] = {a, b};
                b++;
        }

        for(int i = 0; i < G.graph.num_vertexes; i++)
        {
                for(int j = 0; j < vertex_pairs.size(); j++)
                {
                        if(vertex_pairs[j][0] == i || vertex_pairs[j][1] == i)
                        {
                                break;
                        }
                        int x1 = arc[vertex_pairs[j][0]][vertex_pairs[j][1]];
                        int x2 = arc[vertex_pairs[j][0]][i];
                        int x3 = arc[i][vertex_pairs[j][1]];
                        if(((x1 == x2) && (x1 == 0)) || ((x1 == x3) && (x1 == 0)))
                                break;
                        if(x2 == 0 || x3 == 0)
                                break;
                        if(x1 > x2 + x3)
                        {
                                arc[vertex_pairs[j][0]][vertex_pairs[j][1]] = x2 + x3; 
                                path[vertex_pairs[j][0]][vertex_pairs[j][1]] = i;
                        }       
                }
        }

        

}

#endif







//Linear_graph_wight
#if 2


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
        friend void kruskal(Linear_graph_wight& G);
        friend void Dijkstra(string t1, string t2, Linear_graph_wight& G);
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

        //get the wight
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
        cout <<   "    ";
        for(int i = 0; i < graph.num_vertexes; i++)
        {
                cout << graph.list[i] << "  ";
        }
        cout << endl;
        for(int i = 0; i < graph.list.size(); i++)
        {
                cout << graph.list[i] << "  ";
                for(int j = 0; j < graph.arc[0].size(); j++)
                {
                        cout << setw(2) <<  graph.arc[i][j] << "  ";
                }
                cout << endl;
        }
}


//DFS traverse the Linear_graph_without_direction
void Dfs(Linear_graph_wight &G, int i, vector<int>& visited)
{
        int j; 
        visited[i] = 1;                                         //mark which one has been print
        cout << G.graph.list[i] << ' ';                         //print the vert
        for(j = 0; j < G.graph.num_vertexes; j++)
                if(G.graph.arc[i][j] != 0 && !visited[j])       //One way to the end and then back
                        Dfs(G,j,visited);
};


void Dfstraverse(Linear_graph_wight &G)
{
        vector<int> visited(G.graph.num_vertexes, 0);           //mark which one has been print
        int i;
        for(i = 0; i < G.graph.num_vertexes; i++)
        {
                if(!visited[i])                                 //if dont print this one
                        Dfs(G, i, visited);
        }
        cout << endl;
};


//use queue, One floor by one floor
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



//The shortest path between a set of selected points and a set of selected points
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



//first, all edges are sorted according to weights, and small weighted edges that do not form loops are selected
void kruskal(Linear_graph_wight& G)
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
        }

        
        //Detect whether it is looped or not 
        vector<int> selected;
        int num_edgs = 0;
        for(int i = 0; num_edgs != G.graph.num_vertexes -1 && i < G.graph.num_edgs; i++)
        {
                if(find_num(begin[i], selected) || find_num(end[i], selected))
                {
                        selected.push_back(end[i]);
                        cout << begin[i] << " > " << end[i] << " = " << wight[i] << endl;
                        num_edgs ++;
                }
        }    

}



//Get the shortest path from one vertex to the others
void Dijkstra(string t1, string t2, Linear_graph_wight& G)
{
        vector<int> verts(G.graph.num_vertexes,0);
        vector<int> go(G.graph.num_vertexes, INT_MAX);
        vector<int> last(G.graph.num_vertexes, INT_MAX);

        int v_begin = 0, v_end = 4;
        
        verts[v_begin] = 1;
        go[v_begin] = 0;
        last[v_begin] = 0;
        int v_v_begin = v_begin;
        for(int j = 0; j < G.graph.num_vertexes; j++)
        {
                
                for(int i = 0; i < G.graph.num_vertexes; i++)
                {
                        if(G.graph.arc[v_v_begin][i] != 0 && G.graph.arc[v_v_begin][i] + go[v_v_begin] < go[i])
                        {
                                go[i] = G.graph.arc[v_v_begin][i] + go[v_v_begin];
                                last[i] = v_v_begin;
                                
                        }
                }

                int min = INT_MAX;
                for(int i = 0; i < G.graph.num_vertexes; i++)
                {
                        if(go[i] < min && go[i] != 0 && verts[i] == 0)
                        {
                                min = go[i];
                                v_v_begin = i;
                        }
                }
                verts[v_v_begin] = 1;
                v_begin = v_v_begin;


        }


}







#endif








#endif