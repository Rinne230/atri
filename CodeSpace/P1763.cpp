    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll dep = 1, st[11], ans[11], flag;
    ll gcd(ll x, ll y){
        if (y == 0) return x;
        else return gcd(y, x % y);
    }
    void dfs(ll a, ll b, ll x){
        if (x > dep) return;
        if (a == 1 && b > st[x - 1]){
            st[x] = b;
            if (!flag || st[x] < ans[x]){
                for (int i = 1; i <= dep; ++i){
                    ans[i] = st[i];
                }
            }
            flag = 1;
            return;
        }
        ll l = max(b / a, st[x - 1] + 1);//原数是a/b，只有分母比b/a+1大，整体才比a/b小，才满足拆的条件
        ll r = (dep - x + 1) * b / a;
        if (flag && r >= ans[dep]) r = ans[dep] - 1;
        for (ll i = l; i < r; ++i){
            st[x] = i;
            ll c = gcd(a * i - b, b * i);
            dfs((a * i - b) / c, b * i / c, x + 1);
        }
    }
    int main(){
        ll a, b;
        cin >> a >> b;
        ll c = gcd(a, b);
        a /= c, b /= c;
        st[0] = 1;
        for (dep = 1; dep <= 10; ++dep){
            dfs(a, b, 1);
            if (flag){
                for (int i = 1; i <= dep; ++i){
                    cout << ans[i] << " ";
                }
                break;
            }
        }
    }

