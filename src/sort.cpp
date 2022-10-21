#include "../include/sort.h"


int main(void)
{

        // vector<int> s = {1,32,435,5432,324,3243,534,345};
        vector<int> s = {9999, 888, 777, 666, 555, 444, 33, 22, 1, 0};
        vector<int> s1 = {0,1,22,333,444,555,6666,7777,8888,9999};
        vector<int> s2 = {444, 22, 555, 9999, 1, 666, 333, 0, 8888, 777};
        vector<int> s3 = {4,2};

        // shellsort(s);
        // Heapsort(s1);
        quicksort(s);
        return 0;
}


