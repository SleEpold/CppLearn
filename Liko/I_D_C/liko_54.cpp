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

bool check(int count, int sum)
{
    return count > sum;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int y = matrix.size();
    int x = matrix[0].size();

    int sum = x * y;
    int count = 1;

    for (int lun = 0; count <= sum; lun++)
    {
        for (int i = lun; i < x - lun; i++)
        {
            ans.push_back(matrix[lun][i]);
            count++;
        }
        if (check(count, sum))
            break;

        for (int i = lun + 1; i < y - lun; i++)
        {
            ans.push_back(matrix[i][x - lun - 1]);
            count++;
        }
        if (check(count, sum))
            break;

        for (int i = x - lun - 2; i > lun; i--)
        {
            ans.push_back(matrix[y - lun - 1][i]);
            count++;
        }
        if (check(count, sum))
            break;

        for (int i = y - lun - 1; i > lun; i--)
        {
            ans.push_back(matrix[i][lun]);
            count++;
        }
        if (check(count, sum))
            break;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> ans = spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}






// class Solution {
// public:
//     bool check(int count, int sum) { return count > sum; }

//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int> ans;
//         int y = matrix.size();
//         int x = matrix[0].size();

//         int sum = x * y;
//         int count = 1;

//         for (int lun = 0; count <= sum; lun++) {
//             for (int i = lun; i < x - lun; i++) {
//                 ans.push_back(matrix[lun][i]);
//                 count++;
//             }
//             if (check(count, sum))
//                 break;

//             for (int i = lun + 1; i < y - lun; i++) {
//                 ans.push_back(matrix[i][x - lun - 1]);
//                 count++;
//             }
//             if (check(count, sum))
//                 break;

//             for (int i = x - lun - 2; i > lun; i--) {
//                 ans.push_back(matrix[y - lun - 1][i]);
//                 count++;
//             }
//             if (check(count, sum))
//                 break;

//             for (int i = y - lun - 1; i > lun; i--) {
//                 ans.push_back(matrix[i][lun]);
//                 count++;
//             }
//             if (check(count, sum))
//                 break;
//         }

//         return ans;
//     }
// };