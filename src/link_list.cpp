
#include "../include/link_list.h"


int main(void)
{
        ElemType nums[] = {1};

        Link x(nums, sizeof(nums)/sizeof(nums[0]));
        x.show();
        x.insert(2,2);
        x.insert(1,2);
        x.show();
        x.add(2);
        x.show();
        x.add(3);
        x.add(4);
        x.add(5);
        x.show();
        x.del(5);
        x.show();
        cout << x[5];


        return 0;
}