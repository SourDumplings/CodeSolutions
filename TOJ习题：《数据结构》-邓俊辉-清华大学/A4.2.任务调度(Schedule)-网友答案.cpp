#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define maxn  4000005
const long long  inf=(long long)1<<32;
#define size 1<<22
#define cmp(A,x,y) (A[x]>a[y]?(x):(y))
struct FastlO /*快速输入输出缓存区设置*/
{
    char inbuf[size];
    char outbuf[size];
    FastlO()
    {
        setvbuf(stdin,inbuf,_IOFBF,size);
        setvbuf(stdout,outbuf,_IOFBF,size);
    }
}IO;
struct node
{
    char s[10];
    long long v;
    bool operator > (node &a)
    {
        return v<a.v || v==a.v && strcmp(s,a.s)<0;
    }
}a[maxn];
int n,m;
int rchild(int x)
{
    return x*2+1;
}
int lchild(int x)
{
    return x*2;
}
//在parent和child之间找到最高优先级代替parent
int replace(int x)
{
    int pa=x;
    if(rchild(x)<=n)
        pa=cmp(a,x,cmp(a,lchild(x),rchild(x)));
    else if(lchild(x)<=n)
        pa=cmp(a,x,lchild(x));
    return pa;
}
void Down(int x)//下滤
{
    int tmp=replace(x);
    while(tmp!=x)
    {
        swap(a[tmp],a[x]);
        x=tmp;
        tmp=replace(x);
    }
}
void work()//批量建堆
{
    for(int i=n/2;i>0;i--)
        Down(i);
}
int  main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%lld%s",&a[i].v,a[i].s);
    work();
    for(i=1;n&&i<=m;i++)
    {
        printf("%s\n",a[1].s);
        a[1].v*=2;
        if(a[1].v>=inf)
            a[1]=a[n--];
        Down(1);
    }
}
