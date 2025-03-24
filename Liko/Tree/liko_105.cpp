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

vector<int> &preorder;
vector<int> &inorder;

unordered_map<int,int> ino;

TreeNode *makeTree(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int lr)
{
    if (pl > pr || il > lr)
        return nullptr;

    int len = ino[preorder[pl]] - il;

    TreeNode *root = new TreeNode(preorder[pl]);
    root->left = makeTree(preorder, inorder, pl + 1, pl + len, il, il + len - 1);
    root->right = makeTree(preorder, inorder, pl + len + 1, pr, il + len + 1, lr);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    for (int i = 0; i < preorder.size(); i++)
    {
        ino[inorder[i]] = i;
    }

    return makeTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size());
}

int main()
{
    TreeNode *tree = new TreeNode();

    return 0;
}


// class Solution {
// public:
//     unordered_map<int, int> ino;

//     TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int pl,
//                        int pr, int il, int lr) {
//         if (pl > pr || il > lr)
//             return nullptr;

//         int len = ino[preorder[pl]] - il;

//         TreeNode* root = new TreeNode(preorder[pl]);
//         root->left =
//             makeTree(preorder, inorder, pl + 1, pl + len, il, il + len - 1);
//         root->right =
//             makeTree(preorder, inorder, pl + len + 1, pr, il + len + 1, lr);
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         for (int i = 0; i < preorder.size(); i++) {
//             ino[inorder[i]] = i;
//         }

//         return makeTree(preorder, inorder, 0, preorder.size() - 1, 0,
//                         preorder.size());
//     }
// };