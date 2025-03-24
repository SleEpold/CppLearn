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

string reversePrefix(string word, char ch)
{
    stack<char> ans;
    int i = 0;
    while (word[i] != ch && i < word.size())
    {
        ans.push(word[i++]);
    }
    if (i < word.size())
    {
        ans.push(word[i++]);
    }
    else if (i >= word.size())
    {
        return word;
    }

    i = 0;

    while (!ans.empty())
    {
        word[i++] = ans.top();
        ans.pop();
    }
    return word;
}

int main()
{
    string word = "abcd";
    char ch = 'z';

    reversePrefix(word, ch);

    return 0;
}


// class Solution {
// public:
//     string reversePrefix(string word, char ch) {
//         stack<char> ans;
//         int i = 0;
//         while (word[i] != ch && i < word.size()) {
//             ans.push(word[i++]);
//         }
//         if (i < word.size()) {
//             ans.push(word[i++]);
//         } else if (i >= word.size()) {
//             return word;
//         }
//         i = 0;

//         while (!ans.empty()) {
//             word[i++] = ans.top();
//             ans.pop();
//         }
//         return word;
//     }
// };