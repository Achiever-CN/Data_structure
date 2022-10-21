#ifndef SORT_H_
#define SORT_H_

#include <iostream>
using namespace std;
#include <vector>

void bubblesort(vector<int> l)
{
        int len = l.size();
        for(int i = len - 1; i > 0; i--)
        {
                for(int j = 0; j < i; j++)
                {
                        if(l[j] > l[j+1])
                        {
                                l[j] += l[j+1];
                                l[j+1] = l[j] - l[j+1];
                                l[j] = l[j] - l[j+1];
                        }
                }
        }
};



void Selectsort(vector<int> l)
{
        int len = l.size();
        int temp, i, j, min = INT_MAX, k;

        for(i = 0; i < len; i++)
        {
                for(j = i; j < len; i++)
                {
                        if(l[j] < min)
                        {
                                min = l[j];
                                k = j;
                        }
                }
                l[i] = temp;
                l[i] = l[k];
                l[k] = temp;
                min = INT_MAX;
        }
};

void insertsort(vector<int>& l)
{
        int len = l.size();
        for(int i = 1; i < len; i++)
        {
                if(l[i] < l[i-1])
                {
                        int temp = l[i];
                        int j;
                        for(j = i-1; j >=0 && l[j] > l[i]; j--)
                                l[j+1] = l[j];
                        l[j+1] = temp;
                }
        }
}

void shellsort(vector<int>& l)
{
        int len = l.size();
        int step = len/2;

        for(int i = 0; step >= 1; step /= 2)
        {
                for(int k = 0; k < step; k++)
                {
                        for(i = k+step; i < len; i += step)
                        {
                                if(l[i] < l[i-step])
                                {
                                        int temp = l[i];
                                        int j;
                                        for(j = i-step; j >= 0 && l[j] > l[i]; j-= step)
                                                l[j+step] = l[j];
                                        l[j+step] = temp;
                                }
                        }
                }
        }

        cout << l[0];

}

void swap(int n1, int n2, vector<int>& l)
{
        int temp = l[n1];
        l[n1] = l[n2];
        l[n2] = temp;
}

void turn_heap(vector<int>& l)
{
        int index;
        for(int i = 1; i < l.size(); i++)
        {
                index = i;
                int father = (index -1) / 2;
                while (l[father] < l[index] && father >= 0)
                {
                        swap(father, index, l);

                        index = father;
                        father = (index -1) / 2;
                }
                
        }
}




void heapify(vector<int>& l, int index, int size)
{
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        while(left < size)
        {
                 int maxindex;
                if(right < size)
                        maxindex = l[right] > l[left] ? right : left;
                else
                        maxindex = left;
                if(l[maxindex] > l[index])
                        swap(index, maxindex, l);
                else
                        break;

                index = maxindex;

                left = 2 * index + 1;
                right = 2 * index + 2;
        }
}



void Heapsort(vector<int>& l)
{
        turn_heap(l);
        int size = l.size();
        while(size > 1)
        {
                swap(0, size -1, l);
                size --;
                heapify(l, 0, size);
        }


}

void quicksort(vector<int>& l, int left, int right)
{
        int stay_left = left, stay_right = right;
        int stand = right;
        if(left >= right)
                return;
        while(left <= right)
        {
                if(left == right)
                {
                        swap(left, stand, l);
                        quicksort(l, stay_left, left - 1);
                        quicksort(l, left+1, stay_right);
                        break;

                }
                if(l[left] > l[stand])
                {
                        if(l[right] < l[stand])
                        {
                                swap(right, left, l);
                                left ++;
                        }
                        else
                                right --;
                }
                else
                        left ++;
                
        }
}


void quicksort(vector<int>& l)
{       
        int left = 0, right = l.size()-1, stand = right;
        int stay_left = left, stay_right = right;

        while(left <= right)
        {
                if(left == right)
                {
                        swap(left, stand, l);
                        quicksort(l, stay_left, left - 1);
                        quicksort(l, left+1, stay_right);
                        break;

                }
                else if(l[left] > l[stand])
                {
                        if(l[right] < l[stand])
                        {
                                swap(right, left, l);
                                left ++;
                        }
                        else
                                right --;
                }
                else
                        left ++;
                
        }

}







#endif