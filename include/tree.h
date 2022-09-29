#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <stdlib.h>
using namespace std;


typedef char ElemType;

struct Tree_list
{
        ElemType data;
        Tree_list* lchild = NULL;
        Tree_list* rchild = NULL;
};


// struct Tree_list_clue
// {
//         ElemType data;
//         Tree_list* lchild = NULL;
//         Tree_list* rchild = NULL;
//         int ltag;
//         int rtag;
// };

class Tree
{

        public:
                Tree(Tree_list*& p);
                void free_tree(Tree_list*& p);
                void show(Tree_list*& p);
                //void turn_clue(Tree_list*& p, Tree_list_clue*& q);

};

Tree :: Tree(Tree_list*& p)
{
       ElemType num;
        cin >> num;
        if(num == '#')
                p = NULL;
        else
        {
                p = new Tree_list;
                if(!p)
                        exit(1);
                p->data = num;
                Tree(p->lchild);
                Tree(p->rchild);
        }
}


void Tree :: free_tree(Tree_list*& p)
{
        if(p)
        {
                free_tree(p->lchild);
                free_tree(p->rchild);
                delete p;
        }
}


void Tree :: show(Tree_list*& p)
{
        if(p)
        {       if(p->data)
                        cout << p->data << ' ';
                else
                        cout << '#' << ' ';
                show(p->lchild);
                show(p->rchild);
        }
}





#endif