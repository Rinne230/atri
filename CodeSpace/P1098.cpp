#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
    char data;
    Node* next;
    Node* pre;
};
Node* p, * r, * head;

void insertx(int num, int p1, int p2, int p3)//✔
{
    Node* ptr;
    Node* s;
    char n, m;
    bool flag = false;
    bool order = true;
    ptr = head->next;
    for (int i = 1; i <= num - 2; i++)
    {
        ptr = ptr->next;
    }
    n = ptr->data;
    m = ptr->next->data;
    if (p1 == 2 && n >= 'a' && m >= 'a')
    {
        n = n - ('a' - 'A');
        m = m - ('a' - 'A');
    }
    else if (p1 == 1 && n <= 'Z' && m <= 'Z' && n >= 'A' && m >= 'A')
    {
        n = n + ('a' - 'A');
        m = m + ('a' - 'A');
    }
    else if (p1 == 3)
    {
        flag = true;
    }
    if (p3 == 2)
    {
        order = false;
    }
    else
    {
        order = true;
    }
    if (order == true)
    {
        for (char i = n + 1; i < m; i++)
        {
            for (int j = 1; j <= p2; j++)
            {
                s = new Node;
                if (flag != true)
                {
                    s->data = i;
                }
                else
                {
                    s->data = '*';
                }
                s->pre = ptr;
                s->next = ptr->next;
                ptr->next = s;
                ptr = ptr->next;
            }
        }
    }
    else
    {
        for (char i = m - 1; i > n; i--)
        {
            for (int j = 1; j <= p2; j++)
            {
                s = new Node;
                if (flag != true)
                {
                    s->data = i;
                }
                else
                {
                    s->data = '*';
                }
                s->pre = ptr;
                s->next = ptr->next;
                ptr->next = s;
                ptr = ptr->next;
            }
        }
    }
}

int search()
{
    int i = 0;
    Node* ptr;
    ptr = head->next;
    while (ptr->next != NULL)
    {
        if ((ptr->data == '-') && (ptr->pre->data < ptr->next->data) && ((ptr->next->data - ptr->pre->data) <= 26) && ptr->next->data != '-' && ptr->pre->data != '-')
        {
            i++;
        }
        ptr = ptr->next;
    }
    return i;
}
int findx()//✔
{
    Node* ptr;
    ptr = head->next;
    int i = 1;
    while (ptr->next != NULL)
    {
        if ((ptr->data == '-') && (ptr->pre->data < ptr->next->data) && ((ptr->next->data - ptr->pre->data) <= 26) && ptr->next->data != '-' && ptr->pre->data != '-')
        {
            ptr->pre->next = ptr->next;
            ptr->next->pre = ptr->pre;
            return i;
        }
        i++;
        ptr = ptr->next;
    }
    return i;
}

int main()
{
    int p1, p2, p3;
    int address;
    int max = 0;
    string str;
    cin >> p1 >> p2 >> p3;
    head = new Node;
    r = head;
    cin >> str;
    for (int i = 0 ; i <= str.length()-1; i++)
    {
        p = new Node;
        p->data = str[i];
        p->next = NULL;
        r->next = p;
        p->pre = r;
        r = p;
    }
    //⬆输入部分✔
    //cout << findx() << endl;findx返回的是插入值的后一个位子即原本'-'号位子
    max = search();
    for (int j = 1; j <= max; j++)
    {
        insertx(findx(), p1, p2, p3);
    }
    //⬇输出部分✔
    p = head->next;
    while (p->next != NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << p->data << endl;
    return 0;
}