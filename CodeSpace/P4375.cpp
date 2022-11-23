#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
struct Node
{
    int loc, val;
}a[maxn];
bool cmp(Node x, Node y) {return x.val < y.val;}
int n, ans = 1, cnt, vis[maxn];
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].loc = i;
    }
    //向后扫会保证把前 ? 个位置上一个值> ? 的数扔到后边去
    //向前扫会保证被换到前? 个位置上的新数的值是≤ ? 的
    //相当于交换了两个数的位置
    //相当于要知道（前?个位置上值>?的数有多少个）的最大值
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i){
        if (i < a[i].loc) cnt++;
        //在不停的拿后面的数字作为参照数字，前面往后赶
        //说明在i+1之前有这么多数字需要往后赶
        //临时参照数字i，如果有东西应在前面且比i大cnt++
        //实际参照数字应该是a[i].loc这个数字在离散话后满足(1,n]的范围且唯一
        if (vis[i]) cnt--;
        //如果前一个if不执行，说明上面那个if不是进行插入排序的条件，如果满足，这个if又正好可以去掉因贡献两次对答案造成的额外+1的影响
        //对于一个数字，比排序的参照数字小被计数，参照数字会因为与后面的比他大反着扫的到前面去的数字计数，一个参照数字贡献了两次
        vis[a[i].loc] = 1;//被移动到后面的数字其实是后面真正的参照物
        ans = max(cnt, ans);
    }
    cout << ans;
    return 0;
}