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

stack<int> ins;
stack<int> ans;

void push(int x)
{
    while (!ans.empty())
    {
        ins.push(ans.top());
        ans.pop();
    }

    ins.push(x);

    while (!ins.empty())
    {
        ans.push(ins.top());
        ins.pop();
    }
}

int pop()
{
    int x = ans.top();
    ans.pop();
    return x;
}

int peek()
{
    return ans.top();
}

bool empty()
{
    return ans.empty();
}

int main()
{

    return 0;
}


// class MyQueue {
// public:
//     MyQueue() {}

//     stack<int> ins;
//     stack<int> ans;

//     void push(int x) {
//         while (!ans.empty()) {
//             ins.push(ans.top());
//             ans.pop();
//         }

//         ins.push(x);

//         while (!ins.empty()) {
//             ans.push(ins.top());
//             ins.pop();
//         }
//     }

//     int pop() {
//         int x = ans.top();
//         ans.pop();
//         return x;
//     }

//     int peek() { return ans.top(); }

//     bool empty() { return ans.empty(); }
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */