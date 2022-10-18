#ifndef SORT_H_
#define SORT_H_

#include <iostream>
using namespace std;
#include <vector>

void bubblesort(vector<int> l)
{
        int len = l.size();

        int min = INT_MAX;
        int temp_i;
        for(int i = 0; i < len; i++)
        {
                for(int j = i; j < len; j++)
                {
                        if(l[j] < min)
                        {
                                min = l[j];
                                temp_i = j;
                        }
                }
                int temp = l[i];
                l[i] = l[temp_i];
                l[temp_i] = temp;
                min = INT_MAX;
        }

        cout <<endl;
};







#endif