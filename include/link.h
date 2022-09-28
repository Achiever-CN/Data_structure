#ifndef LINK_H_
#define LINK_H_

#include <iostream>
using namespace std;

#define MAXSIZE 20              //the maximum length of the linear table
typedef int ElemType;           //define a data type


typedef struct
{
    ElemType data[MAXSIZE];     //creat a linear table
    int length;                 //the length of all data
}Sqlist;

class Linkear_table
{
    private:
        Sqlist list;
    public:

        typedef int ElemType;           //define a data type 
        typedef struct
        {
            ElemType data[MAXSIZE];     //creat a linear table
            int length;                 //the length of all data
        }Sqlist;

        Linkear_table(ElemType nums[], int len);
        ~Linkear_table();
        int insret(int location, ElemType num);
        void show();
        ElemType show(int location);
        void push_back(ElemType num);
        void del(int location);

};


Linkear_table :: Linkear_table(ElemType nums[], int len)
{
    int i = 0;
    for(; i < len; i++)
    {
        if(i < MAXSIZE)
        {
            list.data[i] = nums[i];
        }
        else
        {
            break;
        }
    }
    list.length = i;
}


Linkear_table :: ~Linkear_table()
{
    //linear table dont need to free;
}


int Linkear_table :: insret(int location, ElemType num)
{
   if(location > list.length || location < 0 || list.length >= MAXSIZE)
   {
        cout << "out of range" << endl;
        return 0;
   } 
   else
   {
        int temp = list.data[location];
        for(int i = location + 1; i <= list.length + 1; i++)
        {      
            list.data[i] = temp;
            temp = list.data[i+1];
        }
   }

    list.data[location] = num;
    list.length++;
    return 1;
}


void Linkear_table :: show()
{
    for(int i = 0; i < list.length; i++)
    {
        cout << list.data[i] << ' ';
    }
}


ElemType Linkear_table :: show(int location)
{
    if(location >= list.length)
    {
        cout << "out of range : show()" << endl;
    }
    return list.data[location];
}


void Linkear_table :: push_back(ElemType num)
{
    list.length ++;
    list.data[list.length-1] = num;
}


void Linkear_table :: del(int location)
{
    for(int i = location; i < list.length; i++)
    {
        list.data[i] = list.data[i+1];
    }
    list.length--;
}


#endif