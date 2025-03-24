#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cin >> n;

    int f[60];

    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    cout << f[n] << endl;

    return 0;
}


// class Solution {
// public:
//     int climbStairs(int n) {

//         int f[60];

//         f[1] = 1;
//         f[2] = 2;

//         for (int i = 3; i <= n; i++)
//             f[i] = f[i - 1] + f[i - 2];

//         return f[n];
//     }
// };