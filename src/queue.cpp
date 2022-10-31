#include "../include/queue.h"

int main(void)
{

        int x[] = {1,2,3,4,5,6,7};
        Queue_link q(x, 7);
        cout << q.fear() << endl;
        cout << q.top() << endl;
        q.pop();
        cout << q.fear() << endl;
        q.push(4);
        cout << q.top() << endl;
        return 0;
}