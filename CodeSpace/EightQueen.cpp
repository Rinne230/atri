#include<iostream>//个人不建议采用头文件，可能和定义的变量或名字起冲突，从而引起编译错误；
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100],b[100],c[100],d[100];
//a数组表示的是行；
//b数组表示的是列；
//c表示的是左下到右上的对角线；
//d表示的是左上到右下的对角线；
int total;//总数:记录解的总数
int n;//输入的数，即N*N的格子，全局变量，搜索中要用
void print()
{
    for(int k=1;k<=n;k++)
        cout<<a[k]<<" ";
    cout<<endl;
    total++;
}
void queen(int i)
{
    if(i>n)
    {
        print();
        return;
    }
    else
    {
        for(int j = 1; j <= n; j++)//尝试可能的位置
        {
            if((!b[j]) && (!c[i + j]) && (!d[i - j + n]))
            {
                a[i] = j, b[j] = 1, c[i + j] = 1, d[i - j + n] = 1;
                queen(i + 1);
                b[j] = 0, c[i + j]=0, d[i - j + n] = 0;
            }
        }
    }
}
int main()
{    
    cin>>n;//输入N*N网格，n已在全局中定义
    queen(1);//第一个皇后
    cout<<total;//输出可能的总数
    return 0;
}
