#include <bits/stdc++.h>

#define LL long long

using namespace std;

const int N = 20010;
LL ans;

int sumRain(vector<int> &hh)
{
    if(hh.size() == 1) return 0;

    LL sum = 0;

    int maxh = 0;
    bool flag = false;

    for (int i = 1; i < hh.size(); i++)
    {
        if (hh[i] < hh[maxh])
        {
            flag = true;
        }
        else
        {
            if (flag)
            {
                int hhh = min(hh[i], hh[maxh]);
                for (int j = maxh + 1; j < i; j++)
                {
                    sum += (hhh - hh[j]);
                }
                maxh = i;
                flag = false;
            }
            else
            {
                maxh = i;
            }
        }
    }

    return sum;
}

int main()
{

    vector<int> height;
    vector<int> a;

    int all = 0;

    cin >> all;
    int kkk;
    for (int i = 0; i < all; i++)
    {
        
        cin >> kkk;
        height.push_back(kkk);
    }
    

    a.clear();

    int max = -1;

    for (int i = 0; i < height.size(); i++) // 找最高点
    {
        if (height[i] > max)
        {
            a.clear();
            max = height[i];
            a.push_back(i);
        }
        else if (height[i] == max)
        {
            a.push_back(i);
        }
    }

    int l, r;

    l = a.front();
    r = a.back();

    vector<int> h;

    h = height;

    h.resize(l+1);

    ans += sumRain(h);

    h.clear();

    for (int i = height.size() - 1; i >= r; i--)
    {
        h.push_back(height[i]);
    }

    ans += sumRain(h);

    if (a.size() != 1)
        for (int i = l + 1; i <= r; i++)
            ans += (height[l] - height[i]);

    cout << ans << endl;

    return 0;
}


// 实际代码
// class Solution {
// public:
//     long long ans;
//     int sumRain(vector<int>& hh) {
//         if (hh.size() == 1)
//             return 0;

//         long long sum = 0;

//         int maxh = 0;
//         bool flag = false;

//         for (int i = 1; i < hh.size(); i++) {
//             if (hh[i] < hh[maxh]) {
//                 flag = true;
//             } else {
//                 if (flag) {
//                     int hhh = min(hh[i], hh[maxh]);
//                     for (int j = maxh + 1; j < i; j++) {
//                         sum += (hhh - hh[j]);
//                     }
//                     maxh = i;
//                     flag = false;
//                 } else {
//                     maxh = i;
//                 }
//             }
//         }

//         return sum;
//     }
//     int trap(vector<int>& height) {
//         vector<int> a;

//         a.clear();

//         int max = -1;

//         for (int i = 0; i < height.size(); i++) // 找最高点
//         {
//             if (height[i] > max) {
//                 a.clear();
//                 max = height[i];
//                 a.push_back(i);
//             } else if (height[i] == max) {
//                 a.push_back(i);
//             }
//         }

//         int l, r;

//         l = a.front();
//         r = a.back();

//         vector<int> h;

//         h = height;

//         h.resize(l + 1);

//         ans += sumRain(h);

//         h.clear();

//         for (int i = height.size() - 1; i >= r; i--) {
//             h.push_back(height[i]);
//         }

//         ans += sumRain(h);

//         if (a.size() > 1)
//             for (int i = l + 1; i <= r; i++)
//                 ans = ans + height[l] - height[i];

//         return ans;
//     }
// };