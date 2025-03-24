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

int main()
{

    vector<int> ans;
    vector<int> nums;
    
    if (nums.size() == 1)
    {
        return 0;
    }

    if (nums.size() == 2)
    {
        if (nums[0] > nums[1])
            return 0;
        else
            return 1;
    }

    nums.push_back(-2147483648);

    for (int i = 1; i < nums.size() - 1; i++)
    {
        int left = nums[i - 1];
        int right = nums[i + 1];

        if (nums[i] > left && nums[i] > right)
        {
            return i;
        }
    }

    return 0;
}
