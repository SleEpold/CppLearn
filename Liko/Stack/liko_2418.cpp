#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int INF = 0x7FFFFFFF;
const int N = 1000010;

struct Student
{
    string name;
    int high;
};

bool compare(Student x, Student y)
{
    return x.high > y.high;
}

int main()
{
    vector<int> ans;
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};

    int len = names.size();

    Student sb[1010];

    for (int i = 0; i < len; i++)
    {
        sb[i].name = names[i];
        sb[i].high = heights[i];
    }

    sort(sb, sb + len, compare);

    for (int i = 0; i < len; i++)
    {
        names[i] = sb[i].name;
        cout << names[i] << " ";
    }


    

    return 0;
}

// class Solution {
// public:
//     struct Student {
//         string name;
//         int high;
//     };

//     static bool comparess(Student x, Student y) { return x.high > y.high; }

//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         int len = names.size();

//         Student sb[1010];

//         for (int i = 0; i < len; i++) {
//             sb[i].name = names[i];
//             sb[i].high = heights[i];
//         }

//         sort(sb, sb + len, comparess);

//         for (int i = 0; i < len; i++) {
//             names[i] = sb[i].name;
//         }

//         return names;
//     }
// };