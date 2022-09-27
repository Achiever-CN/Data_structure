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

        Linkear_table();
        int insret(int location);
};



int Linkear_table :: insret(int location)
{
    if( location >= 1 && location <= list.length && list.length < MAXSIZE)
    {
        for(int i = location; i < list.length; i++)
        {
            
        }
    }


}









#endif