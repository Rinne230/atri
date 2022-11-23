#include <bits/stdc++.h>
using namespace std;
#define maxn 2000*75+5
int trie[maxn][26];
int word[maxn];
char str[81];
int n = 0, top = 0 ,ans = 0;
void insert(char *str){
    int u = 0;
    int len = strlen(str);
    int res = 0;
    for(int i = 0; i < len; ++i){
        int a = str[i] - 'a';
        if (trie[u][a] == 0)
            trie[u][a] = ++top;
        u = trie[u][a];
        res += word[u];
    }
    word[u]++;
    ans = max(ans, res + 1);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> str;
        insert(str);
    }
    cout << ans << endl;
    return 0;
}