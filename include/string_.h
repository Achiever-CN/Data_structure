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


vector<int> get_next(string s)	//��vector�������Ӵ�b��next����
{
	vector<int> result;		//��������()����ȷ����С����ʵ�����Ԫ�ز���Ĭ�ϸ�ֵΪ0�ˣ�����һ���յ�������OK��
	int i, j;
	i = 1;
	j = 0;
	result.push_back(0);	//��������Ԫ�ظ�ֵ����Ϊ��ʶʹ��
	while (i < s.size())
	{
		if (j == 0)	//s[i]��ʾ��׺�ĵ����ַ� s[j]��ʾǰ׺�ĵ����ַ�
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
			j = result[j];		//���ַ���ͬ��ǰ׺�ַ�����
	}
	return result;
}

#endif