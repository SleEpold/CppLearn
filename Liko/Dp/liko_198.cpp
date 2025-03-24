#include <bits/stdc++.h>

using namespace std;

const int  N = 110;

int w[N];
int f[N];

int main() {

    int nums[N] = {1,2,3,1};

    int len = sizeof(nums);
    // int len = 4;

    for (int i = 0, j = 1; i < len; i++)
        w[j++] = nums[i];
    
    f[1] = w[1];

    for (int i = 2; i <= len; i++)
    {
        f[i] = max(f[i - 1], f[i - 2] + w[i]);
    }
    

    cout << f[len] << endl;

    return 0;
}



// 实际提交代码
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int len = nums.size();
//         // int len = 4;
//         int w[110];
//         int f[110];

//         for (int i = 0, j = 1; i < len; i++)
//             w[j++] = nums[i];

//         f[1] = w[1];

//         for (int i = 2; i <= len; i++) {
//             f[i] = max(f[i - 1], f[i - 2] + w[i]);
//         }

//         return f[len];
//     }
// };