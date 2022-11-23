#include <bits/stdc++.h>
#define maxn 10000*50+5
using namespace std;
int trie[maxn][26];
int word[maxn], cnt[maxn];
char str[50];
int n, m, top = 0;
void insert(char *str){
    int u = 0;
    int len = strlen(str);
    for (int i = 0; i < len; ++i){
        int a = str[i] - 'a';
        if (trie[u][a] == 0){
            trie[u][a] = ++top;
        }
        u = trie[u][a];
    }
    word[u]++;
}
int find(char *str){
    int u = 0;
    int len = strlen(str);
    for (int i = 0; i < len; ++i){
        int a = str[i] - 'a';
        if(trie[u][a] == 0)
            return -1;
        u = trie[u][a];
    }
    return word[u] ? cnt[u]++ : -1;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> str;
        insert(str);
    }
    cin >> m;
    for (int i = 0; i < m; ++i){
        int res;
        cin >> str;
        res =  find(str);
        if (res == -1) cout << "WRONG" << endl;
        else if (res == 0) cout << "OK" << endl;
        else cout << "REPEAT" << endl;
    }
}