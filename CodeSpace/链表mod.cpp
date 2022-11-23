#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *pre;
    Node *nxt;
}*p, *r, *head;
int n, num, pos;
void insert(int p, int m){//插入一个值
    Node *ptr, *s;
    s = new Node;
    s->data = m;
    ptr = head->nxt;
    for (int i = 1; i < p - 1; ++i) ptr = ptr->nxt;
    s->pre = ptr;
    s->nxt = ptr->nxt;
    ptr->nxt = s;
}
void del(int p){//删除一个值
    Node *ptr;
    ptr = head->nxt;
    for (int i = 1; i < p - 1; ++i) ptr = ptr->nxt;
    ptr->nxt = ptr->nxt->nxt;
    ptr->nxt->pre = ptr;
}
int main(){
    head = new Node;
    r = head;
    cin >> n;
    for (int i = 1; i <= n; ++i){//输入
        cin >> num;
        p = new Node;
        p->data = num;
        p->nxt = nullptr;
        r->nxt = p;
        p->pre = r;
        r = p;
    }
    cin >> pos >> num;
    insert(pos, num);
    p = head->nxt;
    cin >> pos;
    del(pos);
    while(p->nxt != nullptr){//输出
        cout << p->data << " ";
        p = p->nxt;
    }
    cout << p->data;
    return 0;
}