#ifndef LINK_GRAPH_H_
#define LINK_GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define Max 100
#define Anytype string


struct EdgeNode_wight
{
        Anytype subscript;
        int wight;
        EdgeNode_wight *next = NULL;
};

struct VertexNode_wight
{
        Anytype vert;
        EdgeNode_wight *edge = NULL;

};

class Link_graph_wight
{
        public:
                Link_graph_wight(int n1, int n2);
                ~Link_graph_wight();
        private:
                VertexNode_wight graph[Max];
                int num_vertx = 0, num_edge;
                
};

Link_graph_wight :: Link_graph_wight(int n1, int n2)
{
        num_vertx = n1;
        num_edge = n2;
        
        for(int i = 0; i < num_vertx; i++)
        {
                cout << "Please input the vertx one by one" << endl;
                cin >> graph[i].vert;
        }

        EdgeNode_wight *p;
        for(int i = 0; i < num_edge; i++)
        {
                cout << "Please enter the vertices on both sides of the line and the wight" << endl;
                string t1, t2;
                int wight;
                cin >> t1 >> t2 >> wight;
                int x = -1;
                for(int j = 0; j < num_edge; j++)
                {
                        if(graph[j].vert == t1)
                                x = j;
                        if(x != -1)
                                break;
                }

                p = new EdgeNode_wight;
                p->wight = wight;
                p->subscript = t2;
                p->next = graph[x].edge;
                graph[x].edge = p;

        }

};

Link_graph_wight :: ~Link_graph_wight()
{
        for(int i = 0 ; i < num_vertx; i++)
        {
                cout << graph[i].vert << ' ';
                EdgeNode_wight*p = graph[i].edge;
                EdgeNode_wight* q;
                while(p)
                {
                        q = p->next;
                        cout << '[' << p->subscript << ' ' << p->wight << "] ";
                        delete p;
                        p = q;
                }
                p = NULL;
                q = NULL;
                cout << endl;
        }



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