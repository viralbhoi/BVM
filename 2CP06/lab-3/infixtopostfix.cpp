#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^' || c=='$')
        return 3;
    return 0;
}
string postfix(string s)
{
    stack<char> st;
    string post = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            post = post + s[i];
        }
        else if (st.empty())
        {
            st.push(s[i]);
        }
        else if (s[i] == '(' ||s[i]=='^')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                post = post + st.top();
                st.pop();
            }
            st.pop();
        }
        else if (priority(s[i]) > priority(st.top()))
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                post = post + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        post = post + st.top();
        st.pop();
    }
    return post;
}

int main()
{
    cout << postfix("a+b+(c^d^e)");
}
