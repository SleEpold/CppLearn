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

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;

    vector<char> str[numRows];
    int len = s.size();
    int j = 0;
    bool f = true;
    str[0].push_back(s[j]);
    for (int i = 1; i < len; i++)
    {
        if (f && j < numRows - 1)
        {
            j++;
        }
        else if (f && j >= numRows - 1)
        {
            f = false;
            j = numRows - 2;
        }
        else if (!f && j > 0)
        {
            j--;
        }
        else if (!f && j <= 0)
        {
            f = true;
            j = 1;
        }
        str[j].push_back(s[i]);
    }

    string ss = "";

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            ss += str[i][j];
        }
    }
    return ss;
}

int main()
{
    string s = "ABCD";

    cout << convert(s, 2);

    return 0;
}



// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows == 1)
//             return s;

//         vector<char> str[numRows];
//         int len = s.size();
//         int j = 0;
//         bool f = true;
//         str[0].push_back(s[j]);
//         for (int i = 1; i < len; i++) {
//             if (f && j < numRows - 1) {
//                 j++;
//             } else if (f && j >= numRows - 1) {
//                 f = false;
//                 j = numRows - 2;
//             } else if (!f && j > 0) {
//                 j--;
//             } else if (!f && j <= 0) {
//                 f = true;
//                 j = 1;
//             }
//             str[j].push_back(s[i]);
//         }

//         string ss = "";

//         for (int i = 0; i < numRows; i++) {
//             for (int j = 0; j < str[i].size(); j++) {
//                 ss += str[i][j];
//             }
//         }
//         return ss;
//     }
// };