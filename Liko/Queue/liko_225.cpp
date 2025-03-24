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

queue<int> ins;
queue<int> ans;

void push(int x)
{
    ins.push(x);

    while (!ans.empty())
    {
        ins.push(ans.front());
        ans.pop();
    }
    
    swap(ins,ans);
}

int pop()
{
    int x = ans.front();
    ans.pop();
    return x;
}

int top()
{
    return ans.front();
}

bool empty()
{
    return ans.empty();
}

int main()
{

    return 0;
}




// class MyStack {
// public:
//     queue<int> ins;
//     queue<int> ans;

//     MyStack() {}

//     void push(int x) {
//         ins.push(x);

//         while (!ans.empty()) {
//             ins.push(ans.front());
//             ans.pop();
//         }

//         swap(ins, ans);
//     }

//     int pop() {
//         int x = ans.front();
//         ans.pop();
//         return x;
//     }

//     int top() { return ans.front(); }

//     bool empty() { return ans.empty(); }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */