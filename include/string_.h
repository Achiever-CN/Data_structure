#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using namespace std;
#include <string>
#include <vector>

vector<int> get_next(string s);
int kmp(string ms, string ss);


int kmp(string ms, string ss)
{
        vector<int> next = get_next(ss);
        int len1 = ss.size();
        int len2 = ms.size();
        for(int i = 0, j = 0; i < len2;)
        {
                
                if(ms[i] == ss[j])
                {
                        if(j == len1 - 1)
                                return i-len1+1;
                        i++;
                        j++;
                }
                else if(j == 0)
                        i++;    
                else
                        j = next[j];
        }
        return -1;

}


vector<int> get_next(string s)	//用vector来保存子串b的next数组
{
	vector<int> result;		//别想着用()帮它确定大小，其实是添加元素并且默认赋值为0了，建立一个空的容器就OK了
	int i, j;
	i = 1;
	j = 0;
	result.push_back(0);	//将容器首元素赋值，作为标识使用
	while (i < s.size())
	{
		if (j == 0)	//s[i]表示后缀的单个字符 s[j]表示前缀的单个字符
		{
                        i++;
			result.push_back(j);
                        j++;
		}
                else if(s[i] == s[j])
                {
                        
                        result.push_back(j);
                        i++;
                        j++;
                }
		else
			j = result[j];		//若字符不同，前缀字符回溯
	}
	return result;
}

#endif