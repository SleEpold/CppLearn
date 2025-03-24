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

const int INF = 0x7FFFFFFF;
const int N = 510, M = 100010;

struct Edge // 边，a表示出点，b表示入点，w表示边的权重
{
    int a, b, w;
} edges[M];

int dist[N], backup[N];
int n, m, k;

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
 
    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，
    //由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    else
        dist[n];


    // return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++)
    {
        int a, b, w;
        edges[i] = {a, b, w};
    }

    int t = bellman_ford();

    if (t == -1)
        printf("impossible");
    else
        printf("%d", t);


    // if (t > 0x3f3f3f3f / 2)
    //     printf("impossible");
    // else
    //     printf("%d", t);

    return 0;
}
