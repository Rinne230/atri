#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
#define mod 1000000007
ll n, m, seed, vmax, a[maxn];
struct C_Tree{
    int l, r;
    mutable ll val;
    C_Tree(int l, int r = 0, ll val = 0) :l(l), r(r), val(val){}
    bool operator <(const C_Tree &b) const{
        return l < b.l;
    }
};
set<C_Tree> T;
#define IT set<C_Tree>::iterator
IT split(int pos){//拆
    IT it = T.lower_bound(C_Tree(pos));
    if (it != T.end() && it->l == pos) return it;
    --it;
    C_Tree tmp = *it;
    if (it->r < pos) return T.end();
    T.erase(it);
    T.insert(C_Tree(tmp.l, pos - 1, tmp.val));
    return T.insert(C_Tree(pos, tmp.r, tmp.val)).first;
}
void assign(int l, int r, ll val){//组
    IT itr = split(r + 1), itl = split(l);
    T.erase(itl, itr);
    T.insert(C_Tree(l, r, val));
}
void add(int l, int r, ll val){
    IT itr = split(r + 1), itl = split(l);
    for (IT it = itl; it != itr; ++it){
        it->val += val;
    }
}
ll queryLth(int l, int r, int k){//区间第k小数字
    vector<pair<ll, int>> vec;
    IT itr = split(r + 1), itl = split(l);
    for (IT it = itl; it != itr; ++it){
        vec.push_back(make_pair(it->val, it->r - it->l + 1));
    }
    sort(vec.begin(), vec.end());
    int i;
    for (i = 0; i < vec.size(); ++i){
        if (vec[i].second < k){
            k -= vec[i].second;
        }else{
            break;
        }
    }
    return vec[i].first;
}
ll ksm(ll x, ll y, ll p){//光速幂
    ll r = 1;
    ll base = x % p;
    while (y){
        if (y & 1) r = r * base % p;
        base = base * base % p;
        y >>= 1;
    }
    return r;
}
ll rnd(){
    ll ret = seed;
    seed = (seed * 7 + 13) % mod;
    return ret;
}
ll calP(ll l, ll r, ll x, ll y){//区间光速幂
   IT itr = split(r + 1), itl = split(l);
   ll ans = 0;
   for (IT it = itl; it != itr; ++it){
    ans = (ans + ksm(it->val, x, y) * (it->r - it->l + 1) % y) % y;
   }
   return ans;
}
int main(){
    cin >> n >> m >> seed >> vmax;
    for (int i = 1; i <= n; ++i){
        a[i] = (rnd() % vmax) + 1;
        T.insert(C_Tree(i, i, a[i]));
    }
    for (int i = 1; i <= m; ++i){
        ll op, l, r, x, y;
        op = (rnd() % 4) + 1;
        l = (rnd() % n) + 1;
        r = (rnd() % n) + 1;
        if (l > r) swap(l, r);
        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % vmax) + 1;
        if (op == 4) y = (rnd() % vmax) + 1;
        if (op == 1){
            add(l, r, x);
        }else if (op == 2){
            assign(l, r, x);
        }else if (op == 3){
            cout << queryLth(l, r, x) << endl;
        }else{
            cout << calP(l, r, x, y) << endl;
        }
    }
    return 0;
}