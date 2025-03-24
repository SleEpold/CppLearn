#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans, nums1 = {1, 2, 3}, nums2 = {2, 5, 6};
    int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;

    while (i < m || j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            ans.push_back(nums1[i++]);
        }
        else
        {
            ans.push_back(nums2[j++]);
        }
        if (i == m || j == n)
            break;
    }

    while (i < m)
    {
        ans.push_back(nums1[i++]);
    }

    while (j < n)
    {
        ans.push_back(nums2[j++]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> ans;
//         int i = 0, j = 0;

//         while (i < m || j < n) {
//             if (i == m || j == n)
//                 break;
//             if (nums1[i] <= nums2[j]) {
//                 ans.push_back(nums1[i++]);
//             } else {
//                 ans.push_back(nums2[j++]);
//             }
//         }

//         while (i < m) {
//             ans.push_back(nums1[i++]);
//         }

//         while (j < n) {
//             ans.push_back(nums2[j++]);
//         }

//         nums1 = ans;
//     }
// };