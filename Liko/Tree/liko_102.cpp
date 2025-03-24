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

vector<vector<int>> ans;
queue<TreeNode *> ne, now;

void BFS(int deep)
{
    vector<int> res;
    ans.push_back(res);
    while (!now.empty())
    {
        TreeNode *a = now.front();
        now.pop();

        ans[deep].push_back(a->val);

        if (a->left)
            ne.push(a->left);
        if (a->right)
            ne.push(a->right);
    }

    while (!ne.empty())
    {
        now.push(ne.front());
        ne.pop();
    }

    if (!now.empty())
        BFS(++ deep);
}

vector<vector<int>> levelOrder(TreeNode *root)
{

    if (!root)
        return ans;

    now.push(root);

    BFS(0);

    return ans;
}

int main()
{
    int n;
    TreeNode *bfs = new TreeNode();

    cin >> n;

    levelOrder(bfs);

    return 0;
}