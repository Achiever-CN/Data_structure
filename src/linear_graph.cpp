#include "../include/linear_graph.h"

int main(void)
{
        L_G_W_D list(9, 14);
        list.show();
        // list.Bfs();
        // list.prim();
        // list.kruskal();
        //  prim(list);
        // list.Dijkstra("v0", "v4");
        // floyd("v0", "v2", list);
        return 0;
 }

 /*
v0 v1 v2 v3 v4 v5 v6 v7 v8
v0 v1 4
v0 v7 8
v1 v7 11
v1 v2 9
v7 v8 7
v7 v6 1
v2 v8 2
v8 v6 6
v2 v3 7
v2 v5 4
v6 v5 2
v3 v5 14
v3 v4 9
v4 v5 10
 */