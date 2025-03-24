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

int g[N][N], dist[N];
bool visited[N];

int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        visited[t] = true;
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof(g));
    while (m--)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        g[x][y] = min(g[x][y], c);
    }
    cout << dijkstra() << endl;
    return 0;
}

// memset的正规用法是只能用来初始化char类型的数组的，也就是说，它只接受0x00-0xFF的赋值。

// 因为char是1字节，memset是按照字节赋值的，相当于把每个字节都设为那个数，所以char型的数组可赋任意值；

// 而对于也常用的int类型，int是4个字节，当memset(,1,sizeof());时，1相当于ASSCII码的1，1转为二进制00000001，当做一字节，一字节8位，int为4字节，所以初始化完每个数为00000001000000010000000100000001 = 16843009；

// memset(,0xff,sizeof()),0xff转为二进制11111111，int为4字节所以最后为11111111111111111111111111111111为-1。(化为二进制补位，然后再赋值)。

// 可以全赋值为0,0的二进制位000000000000000000000000000000000，还可以是-1，-1的二进制就是11111111111111111111111111111111，所以memset可以直接初始化(0,-1);
// 例如：0xff转为二进制位11111111，正好是一位，0x1f小于0xff，而0x59也小于0xff，所以这些都可以用来初始化，只要能填满8位的二进制，就可以了。
// 如果你想初始最大化，第一位为符号位，不能为1，剩下全是1，也就是7个1,1111111化为十六进制正好为0x7f，所以memset(,0x7f,sizeof());就可以了

// Memset中无穷大常量的设定技巧
// 如果问题中各数据的范围明确，那么无穷大的设定不是问题，在不明确的情况下，很多程序员都取0x7fffffff作为无穷大，因为这是32-bit int的最大值。如果这个无穷大只用于一般的比较（比如求最小值时min变量的初值），那么0x7fffffff确实是一个完美的选择，但是在更多的情况下，0x7fffffff并不是一个好的选择。
// 很多时候我们并不只是单纯拿无穷大来作比较，而是会运算后再做比较，例如在大部分最短路径算法中都会使用的松弛操作：
// 　　if (d[u]+w[u][v]<d[v]) d[v]=d[u]+w[u][v];
// 我们知道如果u,v之间没有边，那么w[u][v]=INF，如果我们的INF取0x7fffffff，那么d[u]+w[u][v]会溢出而变成负数，我们的松弛操作便出错了，更一般的说，0x7fffffff不能满足“无穷大加一个有穷的数依然是无穷大”，它变成了一个很小的负数。
// 除了要满足加上一个常数依然是无穷大之外，我们的常量还应该满足“无穷大加无穷大依然是无穷大”，至少两个无穷大相加不应该出现灾难性的错误，这一点上0x7fffffff依然不能满足我们。
// 所以我们需要一个更好的家伙来顶替0x7fffffff，最严谨的办法当然是对无穷大进行特别处理而不是找一个很大很大的常量来代替它（或者说模拟它），但是这样会让我们的编程过程变得很麻烦。在我读过的代码中，最精巧的无穷大常量取值是0x3f3f3f3f，我不知道是谁最先开始使用这个精妙的常量来做无穷大，不过我的确是从一位不认识的ACMer(ID:Staginner)的博客上学到的，他/她的很多代码中都使用了这个常量，于是我自己也尝试了一下，发现非常好用，而当我对这个常量做更深入的分析时，就发现它真的是非常精巧了。

// 0x3f3f3f3f的十进制是1061109567，也就是10^9级别的（和0x7fffffff一个数量级），而一般场合下的数据都是小于10^9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。
// 另一方面，由于一般的数据都不会大于10^9，所以当我们把无穷大加上一个数据时，它并不会溢出（这就满足了“无穷大加一个有穷的数依然是无穷大”），事实上0x3f3f3f3f+0x3f3f3f3f=2122219134，这非常大但却没有超过32-bit int的表示范围，所以0x3f3f3f3f还满足了我们“无穷大加无穷大还是无穷大”的需求。
// 最后，0x3f3f3f3f还能给我们带来一个意想不到的额外好处：如果我们想要将某个数组清零，我们通常会使用memset(a,0,sizeof(a))这样的代码来实现（方便而高效），但是当我们想将某个数组全部赋值为无穷大时（例如解决图论问题时邻接矩阵的初始化），就不能使用memset函数而得自己写循环了（写这些不重要的代码真的很痛苦），我们知道这是因为memset是按字节操作的，它能够对数组清零是因为0的每个字节都是0，现在好了，如果我们将无穷大设为0x3f3f3f3f，那么奇迹就发生了，0x3f3f3f3f的每个字节都是0x3f！所以要把一段内存全部置为无穷大，我们只需要memset(a,0x3f,sizeof(a))。

// 所以在通常的场合下，0x3f3f3f3f真的是一个非常棒的选择。

// 其他赋值：

// memset(arr,0x7F,sizeof(arr)); //它将arr中的值全部赋为2139062143，这是用memset对int赋值所能达到的最大值

// 类似的还有：

// memset(arr,0x80,sizeof(arr)); //set int to -2139062144
// memset(arr,0x7F,sizeof(arr)); //set double to 1.38242e+306
// memset(arr,0xFE,sizeof(arr)); //set double to -5.31401e+303