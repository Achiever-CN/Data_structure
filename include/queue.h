#ifndef QUEUE__H_
#define QUEUE__H_

#include <iostream>
using namespace std;
#define MAX 100

class Queue_linear
{
        public:
                Queue_linear();
                Queue_linear(int * l, int len);
                // ~Queue_linear();
                void pop();
                int top();
                int fear();
                void push(int x);

        private:
                int list[MAX];
                int _top = MAX-1;
                int _fear = MAX-1;
};

Queue_linear :: Queue_linear(int * l, int len)
{
        for(int i = 0; i < len; i ++)
        {
                list[_top] = *l;
                _top --;
                l++;
        }
        
}

void Queue_linear:: pop()
{
        if(_fear >= _top)
        {
                _fear --;
        }
        else
                cout << "no more element" << endl;
}

int Queue_linear:: top()
{
        return list[_top+1];
}

int Queue_linear:: fear()
{
        return list[_fear];
}

void Queue_linear:: push(int x)
{
        list[_top--] = x;
}



struct Queue
{
        int data;
        Queue * next = NULL;
        Queue * last = NULL;
};


class Queue_link
{
        public:
                Queue_link(int * l, int len);
                ~Queue_link();
                void pop();
                void push(int x);
                int top();
                int fear();
                
        private:
                Queue *_top;
                Queue *_fear;

};

Queue_link:: Queue_link(int * l, int len)
{
        Queue *p = new Queue;
        _fear = p;
        for(int i = 0; i < len; i++)
        {
                p->data = *l;
                l++;
                if(i + 1 < len)
                {
                        p->last = new Queue;
                        p->last->next = p;
                        p = p->last;
                }
        }
        _top = p;
}

void Queue_link:: pop()
{
        if(_fear->last != _top)
        {
                _fear = _fear->last;
                delete _fear->next;
        }
        else
                cout << "no elements" << endl;
}

void Queue_link:: push(int x)
{
        Queue *p = new Queue;
        p->data = x;
        p->next = _top;
        _top = p;
}


int Queue_link:: top()
{
        return _top->data;
}

int Queue_link:: fear()
{
        return _fear->data;
}

Queue_link :: ~Queue_link()
{
        while(_top != _fear && _top->next != _fear)
        {
                Queue *p = _top->next;
                delete _top;
                _top = p;

                p = _fear->last;
                delete _fear;
                _fear = p;
        }
        if(_top != _fear)        
                delete _fear;
        delete _top;
}

#endif