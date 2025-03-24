#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <list>
#include <cstring>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

using namespace std;

const int INF = 0x7FFFFFFF;
const int N = 1000010;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> heap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = heap.find(target - nums[i]);
        if (it != heap.end())
            return {it->second,i};
        heap[nums[i]] = i;
    }
    return {};
}

int main()
{

    vector<int> nums;
    int target;

    twoSum(nums,target);

    return 0;
}


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };