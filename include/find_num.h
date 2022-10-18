#ifndef FIND_NUM_H_
#define FIND_NUM_H
#include <iostream>
using namespace std;

int F(int x)
{
        int s[10] = {0,1,1,2,3,5,8,13,21,34};
        return s[x];
};

int Fibonacci_Search(int *list, int n, int key)
{
       int low, high, mid, i, k;
       low = 0;
       high = n-1;
       k = 0;
       while(n > F(k) - 1)
                k++;

        while(low < high)
        {
                mid = low + F(k-1);
                if(key < list[mid])
                {
                        high = mid -1;
                        k = k-1;
                }
                else if(key > list[mid])
                {
                        low = mid + 1;
                        k = k-2;
                }
                else
                {
                        if(mid <= n)
                                return mid;
                        else
                                return n;
                }
        }
        return 0;
};



#endif