//the importint is KMP

#include "../include/string_.h"

int main(void)
{
        string s = "abcabcaabcacc";
        string ss = "aab";
        cout << kmp(s,ss);
        return 0;
}

