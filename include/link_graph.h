#ifndef LINK_GRAPH_H_
#define LINK_GRAPH_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stack>


using namespace std;
#define Max 100
#define int_max 53326
#define Anytype string


struct EdgeNode_wight
{
        int subscript;
        int wight;
        EdgeNode_wight *next = NULL;
};

struct VertexNode_wight
{
        Anytype vert;
        int in = 0;
        EdgeNode_wight *edge = NULL;

};


struct Link_graph_wight
{
        VertexNode_wight graph[Max];
        int num_Vertexes, num_Edges;
};




class L_G_W
{
        public:
                L_G_W(int n1, int n2);
                ~L_G_W();
                int topologicalSort();
                void Critica1Path();
        private:
                Link_graph_wight G;
                
};

L_G_W :: L_G_W(int n1, int n2)
{
        G.num_Vertexes = n1;
        G.num_Edges = n2;

        for(int i = 0; i < G.num_Vertexes; i++)
        {
                cout << "Please input the vertx one by one" << endl;
                cin >> G.graph[i].vert;
        }

        EdgeNode_wight *p;
        for(int i = 0; i < G.num_Edges; i++)
        {
                cout << "Please enter the vertices on both sides of the line and the wight" << endl;
                string t1, t2;
                int wight;
                cin >> t1 >> t2 >> wight;
                int x = -1, y = -1;
                for(int j = 0; j < G.num_Vertexes; j++)
                {
                        if(G.graph[j].vert == t1)
                                x = j;
                        if(G.graph[j].vert == t2)
                                y = j;
                        if(x != -1 && y != -1)
                                break;
                }

                G.graph[y].in++;

                p = new EdgeNode_wight;
                p->wight = wight;
                p->subscript = y;
                
                p->next = G.graph[x].edge;
                G.graph[x].edge = p;


        }

};

L_G_W :: ~L_G_W()
{
        for(int i = 0 ; i < G.num_Vertexes; i++)
        {
                cout << setw(4) << G.graph[i].vert << "  ";
                EdgeNode_wight*p = G.graph[i].edge;
                EdgeNode_wight* q;
                while(p)
                {
                        q = p->next;
                        cout << "[ " << G.graph[p->subscript].vert << " " << p->wight << " ]  ";
                        delete p;
                        p = q;
                }
                p = NULL;
                q = NULL;
                cout << endl;
        }



}


int L_G_W :: topologicalSort()
{
        stack<int> s;
        int count = 0;
        Link_graph_wight temp_g = G;
        

        for(int i = 0; i < temp_g.num_Vertexes; i++)
                if(temp_g.graph[i].in == 0)
                        s.push(i);

        while(! s.empty())
        {
                int temp = s.top();
                s.pop();
                cout << temp_g.graph[temp].vert << "  ";
                count++;

                EdgeNode_wight* e = temp_g.graph[temp].edge;
                for(; e; e = e->next)
                {
                        int k = e->subscript;
                        if( !(-- temp_g.graph[k].in))
                                s.push(k);
                }
        }

        if(count < temp_g.num_Vertexes)
                return 0;
        return 1;
}



void L_G_W :: Critica1Path()
{
        stack<int> s;
        stack<int> s2;
        vector<int> etv(G.num_Vertexes, 0);
        
        Link_graph_wight g = G;
        EdgeNode_wight* e;

        for(int i = 0; i < g.num_Vertexes; i++)
        {
                if(g.graph[i].in == 0)
                        s.push(i);
        }

        while(! s.empty())
        {
                int t1 = s.top();
                s.pop();
                s2.push(t1);

                for(e = g.graph[t1].edge; e; e = e->next)
                {
                        int k = e->subscript;
                        if(! (-- g.graph[k].in))
                                s.push(k);
                        if(etv[t1] + e->wight > etv[k])
                                etv[k] = etv[t1] + e->wight;
                                
                }
        }
        vector<int> ltv(G.num_Vertexes, etv[g.num_Vertexes -1]);
        while(! s2.empty())
        {
                int t1 = s2.top();
                s2.pop();

                for(e = g.graph[t1].edge; e; e = e->next)
                {
                        int k = e->subscript;
                        if(etv[k] - e->wight < ltv[t1])
                                ltv[t1] = etv[k] - e->wight;
                }
        }

        cout << g.graph[0].vert;
        for(int i = 1; i < g.num_Vertexes; i++)
        {
                if(etv[i] == ltv[i])
                        cout << " -> " <<  g.graph[i].vert;
        }
        cout << "  " << ltv[g.num_Vertexes-1] << endl;
 
}
















//without driection

struct EdgeNode_without_wight
{
        Anytype subscript;
        int wight;
        EdgeNode_without_wight *next = NULL;
};

struct VertexNode_withoutwight
{
        Anytype vert;
        EdgeNode_without_wight *edge = NULL;

};


class Link_graph_withoutwight
{
        public:
                Link_graph_withoutwight(int n1, int n2);
                ~Link_graph_withoutwight();
        private:
                VertexNode_withoutwight graph[Max];
                int num_vertx = 0, num_edge;
                
};

Link_graph_withoutwight :: Link_graph_withoutwight(int n1, int n2)
{
        num_vertx = n1;
        num_edge = n2;
        
        for(int i = 0; i < num_vertx; i++)
        {
                cout << "Please input the vertx one by one" << endl;
                cin >> graph[i].vert;
        }

        EdgeNode_without_wight *p;
        for(int i = 0; i < num_edge; i++)
        {
                cout << "Please enter the vertices on both sides of the line" << endl;
                string t1, t2;
                int wight;
                cin >> t1 >> t2;
                int x = -1, y = -1;
                for(int j = 0; j < num_edge; j++)
                {
                        if(graph[j].vert == t1)
                                x = j;
                        if(graph[j].vert == t2)
                                y = j;
                        if(x != -1 && y != -1)
                                break;
                }

                p = new EdgeNode_without_wight;
                p->subscript = t2;
                p->next = graph[x].edge;
                graph[x].edge = p;

                p = new EdgeNode_without_wight;
                p->subscript = t1;
                p->next = graph[y].edge;
                graph->edge = p;

        }

};

Link_graph_withoutwight :: ~Link_graph_withoutwight()
{
        for(int i = 0 ; i < num_vertx; i++)
        {
                cout << graph[i].vert << ' ';
                EdgeNode_without_wight* q;
                EdgeNode_without_wight* p = graph[i].edge;
                while(p)
                {
                        q = p->next;
                        cout << '[' << p->subscript << "] ";
                        delete p;
                        p = q;
                }
                p = NULL;
                q = NULL;
                cout << endl;
        }



}










#endif