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

        Linkear_table(int nums[]);
        int insret(int location, int num);
        void show();
};

Linkear_table :: Linkear_table(int nums[])
{
    int i = 0;
    for(; nums[i]; i++)
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



int Linkear_table :: insret(int location, int num)
{
    int temp;
    location --;
    if( location >= 1 && location < list.length && list.length < MAXSIZE)
    {
        for(int i = location; i < list.length; i++)
        {
            temp = list.data[i+1];
            list.data[i+1] = list.data[i];
        }
        list.data[location] = num;
    }
    else
    {
        cout << "Out of range" << endl;
        return 0;
    }
    return 1;


}

void Linkear_table :: show()
{
    for(int i = 0; i < list.length; i++)
    {
        cout << list.data[i] << ' ';
    }
}







#endif