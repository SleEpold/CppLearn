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

int h[N];
int hmax;
int head = 1;
int tt = 1;
int hsize;

int MyCircularQueue(int k)
{
    hmax = k;
}

bool enQueue(int value)
{
    if (hsize < hmax)
    {
        h[tt] = value;
        tt++;
        if (tt > hmax)
            tt = 1;
        hsize++;
        return true;
    }
    else
        return false;
}

bool deQueue()
{
    if (hsize > 0)
    {
        h[head] = -1;
        head++;
        if (head > hmax)
            head = 1;
        hsize--;
        return true;
    }
    else
        return false;
}

int Front()
{
    if (hsize > 0)
        return h[head];
    else
        return -1;
}

int Rear()
{
    if (hsize > 0)
    {
        int k = tt - 1;
        if (k == 0)
            k = hmax;
        return h[k];
    }
    else
        return -1;
}

bool isEmpty()
{
    return hsize <= 0;
}

bool isFull()
{
    return hsize == hmax;
}

int main()
{

    vector<int> ans;

    return 0;
}



// class MyCircularQueue {
// public:
//     int h[10010];
//     int hmax;
//     int head = 1;
//     int tt = 1;
//     int hsize;

//     MyCircularQueue(int k) { hmax = k; }

//     bool enQueue(int value) {
//         if (hsize < hmax) {
//             h[tt] = value;
//             tt++;
//             if (tt > hmax)
//                 tt = 1;
//             hsize++;
//             return true;
//         } else
//             return false;
//     }

//     bool deQueue() {
//         if (hsize > 0) {
//             h[head] = -1;
//             head++;
//             if (head > hmax)
//                 head = 1;
//             hsize--;
//             return true;
//         } else
//             return false;
//     }

//     int Front() {
//         if (hsize > 0)
//             return h[head];
//         else
//             return -1;
//     }

//     int Rear() {
//         if (hsize > 0){
//             int k = tt - 1;
//             if (k == 0) k = hmax;
//             return h[k];
//         }
//         else
//             return -1;
//     }

//     bool isEmpty() { return hsize <= 0; }

//     bool isFull() { return hsize == hmax; }
// };

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */