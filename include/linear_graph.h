#ifndef LINEAR_GRAPH_H_
#define LINEAR_GRAPH_H_

#include <iostream>
#include <string>
#include <queue>
#include <vector>
// #include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define n 100
#define int_max 53362

struct linear_graph
{
        vector<string> list;            
        vector<vector<int>> arc;        
        int num_vertexes, num_edgs;   
};


void print_path(int u, int v, vector<vector<int>> path, vector<string> list)
{
        if(path[u][v] == -1)
        {
            cout << list[u] << " -> ";    
        }
        else
        {
                int mid = path[u][v];
                print_path(u,mid, path, list);
                print_path(mid,v, path, list);

        }
};


int find_subscript(string t1, vector<string> list)
{
        for(int i = 0; i < list.size(); i++)
                if(list[i] == t1)
                        return i;
        return -1;
};

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
};



//Linear_graph_without_direction
class L_G_W
{
        public:
                L_G_W(int n1, int n2);
                ~L_G_W(){};
                void Dfs();
                void Bfs();
                void prim ();
                void kruskal();
                void Dijkstra(string t1, string t2);
                void floyd(string t1, string t2);
                void show();
        protected:
                linear_graph graph;
                void Dfstraverse(int i, vector<int>& visited);
                
};


L_G_W:: L_G_W(int n1,int n2)
{
        graph.num_vertexes = n1;
        graph.num_edgs = n2;
        
        //reset the arc[][],and set the initial value;
        //get vertex
        string temp;
        graph.arc.resize(graph.num_vertexes);
        for(int i = 0; i < graph.num_vertexes; i++)
        {
                graph.arc[i].resize(n1);
                graph.arc[i].assign(n1,int_max);
                graph.arc[i][i] = 0;


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

                int x = find_subscript(t1, graph.list);
                int y = find_subscript(t2, graph.list);

                if(x == -1 || y == -1)
                {                
                        cout << "input error: cant find the vertex" << endl;
                        abort();
                }
                graph.arc[x][y] = temp;
                // graph.arc[y][x] = temp;


        }
}


//DFS traverse the Linear_graph_without_direction
void L_G_W :: Dfstraverse(int i, vector<int>& visited)
{
        int j; 
        visited[i] = 1;                                         //mark which one has been print
        cout << graph.list[i] << ' ';                         //print the vert
        for(j = i+1; j < graph.num_vertexes; j++)
                if(graph.arc[i][j] != int_max && !visited[j])       //One way to the end and then back
                        Dfstraverse(j,visited);
};


void L_G_W :: Dfs()
{
        vector<int> visited(graph.num_vertexes, 0);
        for(int i= 0; i < graph.num_vertexes; i++)
        {
                if(!visited[i])
                        Dfstraverse(i,visited);
        }
        cout << endl;
}


//use queue, One floor by one floor
void L_G_W :: Bfs()
{
        vector<int> visited(graph.num_vertexes, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        

        while(! q.empty())
        {
                int temp = q.front();
                q.pop();
                cout << graph.list[temp] << ' ';
                for(int i = temp+1; i < graph.num_vertexes; i++)
                {
                        if(graph.arc[temp][i] != int_max && visited[i] == 0)
                        {
                                q.push(i);
                                visited[i] = 1;
                        }    
                }
        }

        cout << endl;

}


// The shortest path between a set of selected points and a set of selected points
void L_G_W :: prim ()
{
        vector<int> selected(graph.num_vertexes, 0);            // whether the marker point is selected
        vector<int> lowcost(graph.num_vertexes, INT_MAX);       // stores possible connection points and weights between two sets
        vector<int> near_point(graph.num_vertexes, 0);          // save the nearliest point, near_point[i] is close to vertex i
        
        int num_selected = 1;
        selected[0] = 1;
        int i = 0, j;

        while(num_selected != graph.num_vertexes)
        {
                
                //update the Shortest way;
                for(j = 0; j < graph.num_vertexes; j++)
                {
                        if(graph.arc[i][j] != int_max && graph.arc[i][j] < lowcost[j] && !selected[j])
                        {
                                lowcost[j] = graph.arc[i][j];
                                near_point[j] = i;
                        }
                }

                // find the nearliest point
                int min = INT_MAX, temp_j;
                for(j = 0; j < graph.num_vertexes; j++)
                {
                        if(lowcost[j] < min && !selected[j])
                        {
                                min = lowcost[j];
                                temp_j = j;
                        }
                }

                selected[temp_j] = 1;
                num_selected ++;
                i = temp_j;
                cout << graph.list[near_point[temp_j]] << " -> " << graph.list[i] << "  ";                

        }
        cout << endl;

}


//first, all edges are sorted according to weights, and small weighted edges that do not form loops are selected
void L_G_W :: kruskal()
{
        vector<int> begin(graph.num_edgs, 0);
        vector<int> end(graph.num_edgs, 0);
        vector<int> wight(graph.num_edgs, 0);
        vector<vector<int>> temp_arc = graph.arc;
        
        // sort the degs by the wight
        for(int i = 0; i < graph.num_edgs; i++)
        {
                int min = INT_MAX;
                int temp_j = 0, temp_k = 0;
                for(int j = 0; j < graph.num_vertexes; j++)
                {
                        for(int k = j; k < graph.num_vertexes; k++)
                        {
                                if(temp_arc[j][k] <= min && temp_arc[j][k] != 0)
                                {
                                        min = temp_arc[j][k];
                                        temp_j = j;
                                        temp_k = k;
                                }
                        }
                }
                begin[i] = temp_j, end[i] = temp_k, wight[i] = min;
                temp_arc[temp_j][temp_k] = INT_MAX;
        }

       
        // Detect whether it is looped or not 
        // add the end to the selected, only one way to the same point   
        vector<int> selected;
        int num_edgs = 0;
        for(int i = 0; num_edgs < graph.num_vertexes -1; i++)
        {
                if(find_num(begin[i], selected) || find_num(end[i], selected))
                {
                        selected.push_back(end[i]);
                        cout << begin[i] << " -> " << end[i] << endl;
                        num_edgs ++;
                }
        }
        

}


//Get the shortest path from one vertex to the others
void L_G_W :: Dijkstra(string t1, string t2)
{
        vector<int> verts(graph.num_vertexes,0);                // save the point which is been check
        vector<int> go(graph.num_vertexes, INT_MAX);            // save the length from the t1 to t2
        vector<int> last(graph.num_vertexes, INT_MAX);          // save the point pass by

        int b = find_subscript(t1, graph.list); 
        int e = find_subscript(t2, graph.list);
        
        verts[b] = 1;
        go[b] = 0;
        last[b] = 0;


        int t_b = b;
        for(int j = 0; j < graph.num_vertexes; j++)
        {
                
                for(int i = 0; i < graph.num_vertexes; i++)
                {
                        if(graph.arc[t_b][i] != int_max && graph.arc[t_b][i] + go[t_b] < go[i])
                        {
                                go[i] = graph.arc[t_b][i] + go[t_b];
                                last[i] = t_b;
                                
                        }
                }

                int min = INT_MAX;
                for(int i = 0; i < graph.num_vertexes; i++)
                {
                        if(go[i] < min && verts[i] == 0)
                        {
                                min = go[i];
                                t_b = i;
                        }
                }
                verts[t_b] = 1;
                b = t_b;
        }


        while(last[e] != int_max && last[e] != e)
        {       
                cout << graph.list[e] << " <- ";
                e = last[e];
        }
        cout << graph.list[e];

}


void L_G_W :: floyd(string t1, string t2)
{
        vector<vector<int>> temp_arc = graph.arc;
        vector<vector<int>> path(graph.num_vertexes);
        int u, v;

        for(int i = 0; i < graph.num_vertexes; i ++)
        {
                path[i].resize(graph.num_vertexes);
                path[i].assign(graph.num_vertexes,-1);
                if(graph.list[i] == t1)
                        u = i;
                if(graph.list[i] == t2)
                        v = i;
        }

//**********************************************************************************************************************************
        for(int x = 0; x < graph.num_vertexes; x++)
        {
                for(int y = 0; y < graph.num_vertexes; y++)
                {
                        for(int z = 0; z < graph.num_vertexes; z++)
                                temp_arc[y][z] > temp_arc[y][x] + temp_arc[x][z] ? temp_arc[y][z] = temp_arc[y][x] + temp_arc[x][z], path[y][z] = x : temp_arc[y][z];
                }
        }
//**********************************************************************************************************************************
        print_path(u,  v, path, graph.list);
        cout << t2 << endl;


}


void L_G_W :: show()
{
        //show the arc
        
        for(int i = -1; i < graph.num_vertexes; i++)
        {
                if(i == -1)
                {
                        cout <<   "    ";
                        for(int j = 0; j < graph.num_vertexes; j++)
                                cout << graph.list[j] << "  ";
                        cout << endl;
                        continue;
                }
                for(int j = -1; j < graph.num_vertexes; j++)
                {
                        if(j == -1)
                        {
                                cout << graph.list[i] << "  ";
                                continue;
                        }
                        if(graph.arc[i][j] == int_max)
                                cout << " ∞  ";
                        else
                                cout << setw(2) <<  graph.arc[i][j] << "  "; 
                }
                cout << endl;
                
        }
}








//Linear_graph_wight

class L_G_W_D : public L_G_W
{
        public:
                L_G_W_D(int n1, int n2);
                ~L_G_W_D(){};
         
};

L_G_W_D :: L_G_W_D(int n1, int n2):L_G_W(n1, n2)
{
        for(int i = 0; i < graph.num_vertexes; i++)
        {
                for(int j = 0; j < graph.num_vertexes; j++)
                {
                        if(graph.arc[i][j] != int_max)
                                graph.arc[j][i] = graph.arc[i][j];
                }
        }
}


#endif