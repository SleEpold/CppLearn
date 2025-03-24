#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int INF = 0x7FFFFFFF;
const int N = 10010;

int n, m;

void insertion_sort(vector<int> &h)
{
    for (int i = 1; i < h.size(); i++)
    {
        int ans = h[i];
        int j = i - 1;
        while (j >= 0 && ans < h[j])
        {
            h[j + 1] = h[j];
            j--;
        }
        h[j + 1] = ans;
    }
}

void bubble_sort(vector<int> &h)
{
    for (int i = 0; i < h.size() - 1; i++)
        for (int j = 0; j < h.size() - i - 1; j++)
            if (h[j] > h[j + 1])
                swap(h[j], h[j + 1]);
}

void selection_sort(vector<int> &h)
{
    for (int i = 0; i < h.size() - 1; i++)
    {
        int ans = h[i];
        int k = i;

        for (int j = i + 1; j < h.size(); j++)
            if (h[j] < ans)
            {
                ans = h[j];
                k = j;
            }

        swap(h[k], h[i]);
    }
}

void quick_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;

    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    // int i = l - 1, j = r + 1, x = q[(l + r + 1)>> 1];
    while (i < j)
    {
        // do while 先移动再判断
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
        // 交换后指针要都移动一位
        // 配合do while 更加优美
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
    // quick_sort(q, l, i - 1), quick_sort(q, i, r);
}

void merge_sort(vector<int> &q, int l, int r)
{
    if (l >= r)
        return ;

    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int i = l, j = mid + 1;

    vector<int> tmp;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j])
            tmp.push_back(q[i++]);
        else
            tmp.push_back(q[j++]);
    }

    while (i <= mid)
        tmp.push_back(q[i++]);

    while (j <= r)
        tmp.push_back(q[j++]);

    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    vector<int> h = {5, 2, 3, 1};

    // insertion_sort(h);
    // bubble_sort(h);
    // quick_sort(h,0,h.size() - 1);
    // selection_sort(h);
    merge_sort(h, 0, h.size() - 1);

    return 0;
}