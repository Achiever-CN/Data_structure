#include "../include/find_num.h"

int main(void)
{
        int a[9] = {1, 16, 24, 35, 47, 59, 62, 73, 88};
        int x = Fibonacci_Search(a, 9, 73);
        cout << x;
        return 0;
}