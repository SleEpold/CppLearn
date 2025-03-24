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

list<int> ans;
int hmax;

bool insertFront(int value)
{
    if (ans.size() < hmax)
    {
        ans.push_front(value);
        return true;
    }
    else
        return false;
}

bool insertLast(int value)
{
    if (ans.size() < hmax)
    {
        ans.push_back(value);
        return true;
    }
    else
        return false;
}

bool deleteFront()
{
    if (ans.size() > 0)
    {
        ans.pop_front();
        return true;
    }
    else
        return false;
}

bool deleteLast()
{
    if (ans.size() > 0)
    {
        ans.pop_back();
        return true;
    }
    else
        return false;
}

int getFront()
{
    if (ans.size() > 0)
        return ans.front();
    else
        return -1;
}

int getRear()
{
    if (ans.size() > 0)
        return ans.back();
    else
        return -1;
}

bool isEmpty()
{
    return ans.size() == 0;
}

bool isFull()
{
    return ans.size() == hmax;
}

int main()
{

    return 0;
}



// class MyCircularDeque {
// public:
//     list<int> ans;

//     int hmax;

//     MyCircularDeque(int k) { hmax = k; }

//     bool insertFront(int value) {
//         if (ans.size() < hmax) {
//             ans.push_front(value);
//             return true;
//         } else
//             return false;
//     }

//     bool insertLast(int value) {
//         if (ans.size() < hmax) {
//             ans.push_back(value);
//             return true;
//         } else
//             return false;
//     }

//     bool deleteFront() {
//         if (ans.size() > 0) {
//             ans.pop_front();
//             return true;
//         } else
//             return false;
//     }

//     bool deleteLast() {
//         if (ans.size() > 0) {
//             ans.pop_back();
//             return true;
//         } else
//             return false;
//     }

//     int getFront() {
//         if (ans.size() > 0)
//             return ans.front();
//         else
//             return -1;
//     }

//     int getRear() {
//         if (ans.size() > 0)
//             return ans.back();
//         else
//             return -1;
//     }

//     bool isEmpty() { return ans.size() == 0; }

//     bool isFull() { return ans.size() == hmax; }
// };

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */