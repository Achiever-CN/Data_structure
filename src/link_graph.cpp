#include "../include/link_graph.h"


int main(void)
{
        L_G_W G(10,13);

        G.Critica1Path();
        
        return 0; 
}


/*
v0 v1 v2 v3 v4 v5 v6 v7 v8 v9 v10 v11 v12 v13
v0 v11 3
v0 v5 3
v0 v4 3
v1 v8 3
v1 v4 3
v1 v2 3
v2 v9 3
v2 v6 3
v2 v5 3
v3 v13 3
v3 v2 3
v4 v7 3
v5 v12 3
v5 v8 3
v6 v5 3
v8 v7 3
v9 v11 3
v9 v10 3
v10 v13 3
v12 v9 3


v0 v1 v2 v3 v4 v5 v6 v7 v8 v9
v0 v2 4
v0 v1 3
v1 v3 5
v1 v4 6
v2 v3 8
v2 v5 7
v3 v4 3
v4 v7 4
v4 v6 9
v5 v7 6
v6 v9 2
v7 v8 5
v8 v9 3


*/