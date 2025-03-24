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

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> buildTree(int l, int r)
{
    if (l > r)
        return {nullptr};

    vector<TreeNode *> ans;

    for (int i = l; i <= r; i++)
    {
        vector<TreeNode *> lfTree = buildTree(l, i - 1);
        vector<TreeNode *> rtTree = buildTree(i + 1, r);
        for (int j = 0; j < lfTree.size(); j++)
        {
            for (int k = 0; k < rtTree.size(); k++)
            {
                TreeNode *root = new TreeNode(i, lfTree[j], rtTree[k]);
                ans.push_back(root);
            }
        }
    }

    return ans;
}

vector<TreeNode *> generateTrees(int n)
{
    return buildTree(1, n);
    ;
}

int main()
{
    int n;

    cin >> n;

    generateTrees(n);

    return 0;
}

// class Solution {
// public:
//     vector<TreeNode*> buildTree(int l, int r) {
//         if (l > r)
//             return {nullptr};

//         vector<TreeNode*> ans;

//         for (int i = l; i <= r; i++) {
//             vector<TreeNode*> lfTree = buildTree(l, i - 1);
//             vector<TreeNode*> rtTree = buildTree(i + 1, r);
//             for (int j = 0; j < lfTree.size(); j++) {
//                 for (int k = 0; k < rtTree.size(); k++) {
//                     TreeNode* root = new TreeNode(i, lfTree[j], rtTree[k]);
//                     ans.push_back(root);
//                 }
//             }
//         }

//         return ans;
//     }

//     vector<TreeNode*> generateTrees(int n) {
//         return buildTree(1, n);
//         ;
//     }
// };