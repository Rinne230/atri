#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
stack<int> st;
int main(){
    ll sum = 0;
    int n, h;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> h;
        if (st.empty()) st.push(h);
        else if (st.top() > h){
            st.push(h);
            sum += st.size() - 1;
        }else{
            while(!st.empty() && st.top() <= h){
                st.pop();
            }
            st.push(h);
            sum += st.size() - 1;
        }
    }
    cout << sum;
    return 0;
}

// for (int i = 1; i <= n; ++i){
//     cin >> h;
//     while (top > 0 && h >= st[top]){
//         top--;
//     }
//     ans += top;
//     top++;
//     st[top] = h;
// }