#ifndef SIZEYS__H_
#define SIZEYS__H
#include <iostream>
#include <stack>
#include <set>
#include <string>

using namespace std;

double compute(string s);
double turn_after(string s);

int main(void)
{
        string s, s1;
        cin >> s;
        s1 = turn_after(s);
        cout << compute(s1);

        return 0;
}

double compute(string s)
{
        stack <double> a;
        set <char> l1 = {'*', '/', '+', '-'};
        for(int i = 0; i < s.size(); i++)
        {
                if(! l1.count(s[i]) && s[i] != ' ')
                {
                        int j;
                        for(j = i; s[j] != ' '; j++){}
                        string s_temp = s.substr(i, j-i);
                        a.push(atof (s_temp.c_str()));
                        i = j;        
                }
                else if(s[i] != ' ')
                {
                        double temp = a.top();
                        a.pop();
                        switch (s[i])
                        {
                        case '+':       a.top() += temp; break;
                        case '-':       a.top() -= temp; break;
                        case '*':       a.top() *= temp; break;
                        case '/':       a.top() /= temp; break;
                        default:
                                break;
                        }
                }   
        }
        return a.top();
}

double turn_after(string s)
{
        stack <char> a;
        set <char> l1 = {'*', '/'};
        set <char> l2 = {'+', '-'};
        set <char> l3 = {']', ')', '}'};
        set <char> l4 = {'[', '(', '{'};
        set <char> l5 = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        string s1;

        for(int i = 0; i < s.size(); i++)
        {
                if(l5.count(s[i]))
                {
                        s1 += s[i];
                        if(i + 1 >= s.size() || ! l5.count(s[i+1]))
                                s1 += ' ';
                }
                else if(l2.count(s[i]))
                {
                        if(a.size())
                        {
                                if(l1.count(a.top()))
                                {
                                        while(a.size() && ! l4.count(a.top()))
                                        {
                                                s1 += a.top();
                                                a.pop();
                                        }
                                }
                        }
                                a.push(s[i]);
                }
                else if(l3.count(s[i]))
                {
                        while(! l4.count(a.top()))
                        {
                                s1 += a.top();
                                a.pop();
                        }
                        a.pop();
                }
                else
                {
                        a.push(s[i]);
                }
        }

        
        while (a.size())
        {
                s1+= a.top();
                a.pop();
        }

        return compute(s1);
}

#endif