#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct  Node{
    ll w, h;
};

bool operator<(Node a, Node b){
    if (a.w != b.w) return a.w > b.w;
    return a.h > b.h;
}

priority_queue<Node> q;

int main(){
    int n, k;
    ll ans = 0, wi;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> wi;
        q.push(Node{wi, 1});
    }
    if ((n - 1) % (k - 1) != 0){
        for (int i = 1; i <= k - 1 - (n - 1) % (k - 1); ++i){
            q.push(Node{0, 1});
        }
    }
    while(q.size() != 1){
        Node tmp;
        ll sum = 0, maxh = 0;
        for (int i = 1; i <= k; ++i){
            tmp = q.top();
            sum += tmp.w;
            maxh = max(maxh, tmp.h);
            q.pop();
        }
        ans += sum;
        q.push(Node{sum, maxh + 1});
    }
    cout << ans << endl << q.top().h - 1 << endl;
    return 0;
}