#include <bits/stdc++.h>
using namespace std;

//      耗时 216 ms 击败39.86%    内存 8.2 MB 击败87.42%

//      回文串分为两大类奇数和偶数 
//      暴力中点枚举分为奇数：中间不管 对比左右两翼.  为偶数： 直接对比两翼
//      暴力中点枚举可以在每个字符中间插入特殊字符(如￥ # @)使字符总数变为奇数
//      插入字符可以使用奇数对比方法解决全部问题     (s + s - 1 = 2s -1)
//      可以使用暴力枚举从中心点对两边推进 直到两端不同或一端到底(下标溢出)
//      比较两翼长度与记录长度 若更长则更新中点位置与两翼长度 直到枚举完成

//      使用滑块可以使用同种计算方法计算两种情况
//      问题要求最长所以可以直接从最长情况开始枚举，一旦得到回文就可直接输出,降低了问题难度
//      滑块直接从最长滑块向下递减，在递增滑块开始位置以枚举所有可能
//      对比滑块两端，直到左端超过右端即为回文，若出现左端与右端不同则不是回文
//      

int main(){

    string sth;

    cin >> sth;

    int ans = -1;       // 记录最终滑块长度 
    int location = 0;   // 记录滑块起始位置

    int orlen = sth.length();   // 字符原始长度

    for(int i = orlen; i > 1; i --)   // 滑块总长 数值
    {
        
        for (int j = 0; j <= orlen - i; j ++)        //滑块起始位置 地址
        {
            int l = j;
            int r = j + i - 1;

            while (sth[l] == sth[r])        // 比较两端是否相同
            {
                l++;
                r--;
                if (l >= r)     //出现回文
                {
                    ans = i;
                    location = j;
                    break;
                }
            }
            
            if (ans != -1) break;

        }

        if (ans != -1) break;
    }
    
    string s;

    if (ans != -1) {        //特判未出现长度超过一的回文
        s = sth[0];
    }else{
        for(int i = location; i <= location + ans - 1; i ++)
        // cout << sth[i] ;
        s += sth[i];        //力扣神经输出方式，这辈子还没人要我写成过方法输出
    }

    cout << s <<  endl;

    return 0;
}


//      实际提交代码

// class Solution {
// public:
//     string longestPalindrome(string s) {

//         string sth;
//         sth = s;

//         int ans = -1;
//         int location = 0;

//         int orlen = sth.length();

//         for (int i = orlen; i > 1; i--) // 滑块总长 数值
//         {

//             for (int j = 0; j <= orlen - i; j++) // 滑块起始位置 地址
//             {
//                 int l = j;
//                 int r = j + i - 1;

//                 while (sth[l] == sth[r]) {
//                     l++;
//                     r--;
//                     if (l >= r) {
//                         ans = i;
//                         location = j;
//                         break;
//                     }
//                 }

//                 if (ans != -1)
//                     break;
//             }

//             if (ans != -1)
//                 break;
//         }

//         s = "";

//         if (ans == -1) {
//             s = sth[0];
//         } else {
//             for (int i = location; i <= location + ans - 1; i++)
//                 // cout << sth[i] ;
//                 s += sth[i];
//         }

//         return s;
//     }
// };