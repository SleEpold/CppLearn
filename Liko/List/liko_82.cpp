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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{

    ListNode *head = new ListNode();

    ListNode *ans = new ListNode(-101, head);

    ListNode *ins = ans;

    while (ins->next && ins->next->next)
    {
        if (ins->next->val == ins->next->next->val)
        {

            while (ins->next->next && ins->next->val == ins->next->next->val)
                ins->next = ins->next->next;

            ins->next = ins->next->next;
        }
        else
        {
            ins = ins->next;
        }
    }

    return 0;
}

// class Solution {

// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (!head) {
//             return head;
//         }

//         ListNode* ans = new ListNode(-101, head);

//         ListNode* ins = ans;

//         while (ins->next && ins->next->next) {
//             if (ins->next->val == ins->next->next->val) {

//                 while (ins->next->next && ins->next->val == ins->next->next->val)
//                     ins->next = ins->next->next;

//                 ins->next = ins->next->next;

//             } else {
//                 ins = ins->next;
//             }
//         }

//         return ans->next;
//     }
// };