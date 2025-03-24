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

string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }

        string fw = "";
        int lc = 0;
        bool flage = true;
        int min = strs[0].size();

        while (flage && lc < min) {
            for (int i = 0; i < strs.size() - 1; i++) {
                if (lc >= min || strs[i][lc] != strs[i + 1][lc]) {
                    flage = false;
                    break;
                }
            }
            if (!flage) {
                break;
            }
            fw += strs[0][lc];
            lc++;
        }

        return fw;
    }

int main()
{
    vector<string> s;
    s.push_back("0123456789");

    cout << s[0][9];

    return 0;
}



// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (!strs.size()) {
//             return "";
//         }

//         string fw = "";
//         int lc = 0;
//         bool flage = true;
//         int min = strs[0].size();

//         while (flage && lc < min) {
//             for (int i = 0; i < strs.size() - 1; i++) {
//                 if (lc >= min || strs[i][lc] != strs[i + 1][lc]) {
//                     flage = false;
//                     break;
//                 }
//             }
//             if (!flage) {
//                 break;
//             }
//             fw += strs[0][lc];
//             lc++;
//         }

//         return fw;
//     }
// };