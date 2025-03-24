#include <bits/stdc++.h>

const int INF = 0x7fffffff;
typedef  long long LL;

using namespace std;

int main()
{

    vector<int> coins;
    int amount;

    vector<int> dp(10010, INF);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

    if (dp[amount] == INF)
            return -1;
        else
            return dp[amount];
}


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {

//         vector<int> dp(amount + 1, amount + 1);

//         dp[0] = 0;

//         for (int i = 1; i <= amount; i++) {
//             for (int j = 0; j < coins.size(); j++) {
//                 if (i - coins[j] >= 0)
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//             }
//         }

//         if (dp[amount] == amount + 1)
//             return -1;
//         else
//             return dp[amount];
//     }
// };