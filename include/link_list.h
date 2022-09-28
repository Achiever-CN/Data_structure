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
        Link_list *p =  head;
        for(int i = 0; i < len; i++)
        {
                p->data = nums[i];
                // cout << p->next << ' ' << p->data << endl;
                if(i +1 < len)
                {
                        p->next = new Link_list;
                        p = p->next;
                }
                
        }
        rear = p;
        cout << p->data << endl;
        p->next = NULL; 
}


Link :: ~Link()
{
       Link_list* q;
       Link_list* p = head;
       while(p)
       {
        q = p->next;
        delete p;
        p = q;
       } 
       head = NULL;
       p = NULL;
       q = NULL;
       
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
        Link_list *p = head;
        Link_list *q = new Link_list;
        for(int i = 0; i < location; i ++)
        {
                if(p->next)
                {
                        p = p->next;
                }
                else
                {
                        cout << "error out of range : Link :: insert()"<< endl;
                        return 0;
                }
        }
        q->data = p->data;
        p->data = num;
        q->next = p->next;
        p->next = q;
        return 1;

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
                Link_list *q = head;
                head = head->next;
                delete q;
                return 1;
        }
        else
        {       
                Link_list *q = p;
                for(int i = 0; i < location; i++)
                {
                        if(!(p->next))
                        {
                                cout << "error out of range : del()" << endl;
                                return 0;
                        }
                        else
                        {
                                q = p;
                                p = p->next;
                        }
                }
                q->next = p->next;
                delete p;
                return 1;
        }

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