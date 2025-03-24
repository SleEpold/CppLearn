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

int DFS(TreeNode *root, int deep)
{
    int ans = 0;

    if (root->left)
    {
        ans = max(DFS(root->left, deep + 1), ans);
    }
    if (root->right)
    {
        ans = max(DFS(root->right, deep + 1), ans);
    }

    return max(ans, deep);
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;

    return max(DFS(root, 1), 1);
}

int main()
{
    int n;

    cin >> n;

    return 0;
}