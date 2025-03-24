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

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main()
{

    ListNode *head = new ListNode(0);
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);

    head->next = l1;
    l1->next = l2;

    int ins[10020];
    memset(ins, 0, sizeof ins);

    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    int i = 0;

    while (head->next)
    {

        if (head == nullptr || head->next == nullptr)
            return false;

        if (!ins[i])
            ins[i++]++;
        else
            return true;

        head = head->next;

        if (i>10000)
        {
            return 0;
        }
        
    }

    cout << 1;

    return 0;
}



// class Solution {
// public:
//     bool hasCycle(ListNode* head) {

//         int cot = 0;

//         if (head == nullptr || head->next == nullptr) {
//             return false;
//         }

//         while (head->next) {

//             if (head == nullptr || head->next == nullptr)
//                 return false;

//             head = head->next;

//             cot++;
//             if (cot > 10000)
//             return true;
//         }

//             return false;
//     }
// };


// class Solution {
// public:
//     bool hasCycle(ListNode* head) {

//         int ins[200020];
//         memset(ins, 0, sizeof ins);

//         int N = 100000;

//         if (head == nullptr || head->next == nullptr) {
//             return false;
//         }

//         while (head->next) {

//             if (head == nullptr || head->next == nullptr)
//                 return false;

//             if (ins[head->val + N])
//                 return true;
//             else
//                 ins[head->val + N]++;

//             head = head->next;
//         }

//         return false;
//     }
// };

