#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include <iostream>
using namespace std;

typedef int ElemType;


struct Link_list
{
        ElemType data;
        Link_list * next;
};

class Link
{
private:
        Link_list *head = new Link_list;
        Link_list *rear;
public:
        Link(ElemType nums[], int len);
        Link(){}
        ~Link();
        void show();
        int insert(int location, ElemType num);
        void add(ElemType num);
        int del(int location);
        ElemType operator[](int num);
};


Link :: Link(ElemType nums[], int len)
{
        Link_list * p = head;
        if(len > 0)
                p->data = nums[0];
        for(int i = 1; i < len; i++)
        {
                p->next = new Link_list;
                p = p->next;
                p->data = nums[i];
        }
        p->next = NULL;
}


Link :: ~Link()
{
        Link_list* p;
       while(head)
       {
                p = head;
                head = head->next;
                delete p;
       } 
       head = NULL;
       p = NULL;
       
}


void Link::show()
{
        Link_list* p = head;
        while (p)
        {
                cout << p->data << ' ';
                p = p->next;
        }
        cout << endl;
}


int Link :: insert(int location, ElemType num)
{
        // Link_list *p = head;
        // Link_list *q = new Link_list;
        // for(int i = 0; i < location; i ++)
        // {
        //         if(p->next)
        //         {
        //                 p = p->next;
        //         }
        //         else
        //         {
        //                 cout << "error out of range : Link :: insert()"<< endl;
        //                 return 0;
        //         }
        // }
        // q->data = p->data;
        // p->data = num;
        // q->next = p->next;
        // p->next = q;
        // return 1;
        Link_list *p = head->next;
        if(location == 0)
        {
                p = new Link_list;
                p->data = num;
                p->next = head;
                head = p;
                
        }
        for(int i = 1; p; i++)
        {
                if(i == location - 1)
                {
                        Link_list *q = new Link_list;
                        q->data = num;
                        q->next = p->next;
                        p->next = q;
                        return 1;
                }
                p = p->next;
        }
        return 0;
}


void Link :: add(ElemType num)
{
        rear->next = new Link_list;
        rear = rear->next;
        rear->data = num;
        rear->next = NULL;
}


int Link :: del(int location)
{
        Link_list* p = head;
        if(location == 0)
        {
                head = head->next;
                delete p;
                return 1;
        }
        else
        {
                for(int i = 0; p; i++)
                {
                        if(i == location - 1)
                        {
                                Link_list* q = p->next;
                                p->next = p->next->next;
                                delete q;
                                q = NULL;
                                return 1;
                        }
                        p = p->next;
                }       
        }

        return 0;    

}


ElemType Link:: operator[](int num)
{
        Link_list* p = head;
        for(int i = 0; i < num; i ++)
        {
                p = p->next;
        }
        if(!p)
        {
                cout << "error out of range: Link []" << endl;
                return 0;
        }
        return p->data;
}

#endif