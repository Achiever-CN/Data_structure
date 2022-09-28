#include "../include/link.h"

int main()
{

    int nums[] = {1};
    Linkear_table x(nums, sizeof(nums)/sizeof(nums[0]));
    // x.insret(0,2);
    x.push_back(3);
    // x.del(2);
    cout << x.show(0);


    return 0;

}