#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <list>
#include <cstring>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int INF = 0x7FFFFFFF;
const int N = 1000010;

int scoreOfParentheses(string s)
{
    stack<string> ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {

            if (ans.top() == "(")
            {
                ans.pop();
                ans.push("1");
                continue;
            }
            else
            {
                int n = 0;

                n += stoi(ans.top());
                ans.pop();

                while (ans.top() != "(")
                {
                    n += stoi(ans.top());
                    ans.pop();
                }
                ans.pop();
                ans.push(to_string(2 * n));
                continue;
            }
        }
        else
            ans.push("(");
    }

    int x = 0;
    while (!ans.empty())
    {
        x += stoi(ans.top());
        ans.pop();
    }

    return x;
}

int main()
{
    string s = "()()";

    int x = scoreOfParentheses(s);

    cout << x;
    return 0;
}