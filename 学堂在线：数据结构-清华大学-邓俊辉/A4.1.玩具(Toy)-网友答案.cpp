#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
const int maxn=40321;//由于此题数字1~8，康托展开的所有情况为8!，共40320种
const int fac[8]={1,1,2,6,24,120,720,5040};//康托展开中用到的0~7的阶乘
int ans[maxn]={0};//存储各阶段的步数
bool mark[maxn]={0};//标志变量，用以确认状态是否访问过
struct Node
{
    int a[8];
    int val;
}s,u,v;//存储每种状态的结构体，val用来储存康托展开的哈希值，a[]用来存储状态
void swap(int &a,int &b)//交换函数
{
	int temp;
	temp=a;
	a=b;
	b=temp;
 }
int contor(Node &t)//康托展开，对每种状态返回唯一的哈希值
{
	int tmp,num=0;
	for(int i=0;i<8;i++)
	{
		tmp=0;
		for(int j=i+1;j<8;j++)
		{
			if(t.a[j]<t.a[i])
				tmp++;
		 }
		num+=tmp*fac[7-i];
	 }
	return num;
 }
void FA(Node &t)// A操作,上下行交换
{
	for(int i=0;i<4;i++)
        swap(t.a[i],t.a[7-i]);
 }
void FB(Node &t) //B操作，每行循环左移一位，因为预处理是从12345678到各个状态，所以B操作反过来
{
	int temp=t.a[0];
    for(int i=1;i<=3;i++)
        t.a[i-1]=t.a[i];
    t.a[3]=temp;
    temp=t.a[7];
    for(int i=7;i>4;i--)
        t.a[i]=t.a[i-1];
    t.a[4]=temp;
 }
void FC(Node &t)//C操作，中间四小块逆时针转一格，因为预处理是从12345678到各个状态，所以C操作反过来
{
	int temp=t.a[1];
    t.a[1]=t.a[2];t.a[2]=t.a[5];t.a[5]=t.a[6];
    t.a[6]=temp;
 }
class Queue//队列，用以进行广度优先搜索
{
private:
	int size;
	int front;
	int rear;
	Node *base;
public:
	Queue(int init=40321);
	bool empty();
	bool push(Node e);
	bool pop();
	Node getfront();
 };
Queue::Queue(int init)//初始化
{
	size=init;
	base=(Node *)malloc(sizeof(Node)*size);
	front=rear=0;
 }
bool Queue::empty()//判断队列是否为空
{
	if(front==rear)
		return true;
	else
		return false;
 }
bool Queue::push(Node e)//元素进入队列
{
	if((rear+1)%size==front)
	{
		return false;
	 }
	else
	{
		base[rear]=e;
		rear=(rear+1)%size;
		return true;
	 }
 }
bool Queue::pop()//元素出队列
{
	if(front==rear)
	{
		return false;
	 }
	front=(front+1)%size;
	return true;
 }
Node Queue ::getfront()//获得队列首部元素
{
	return base[front];
 }
void bfs()//广度优先搜索进行预处理
{
	for(int i=0;i<8;i++)//从123458678到各个状态
	{
		u.a[i]=i+1;
	 }
	 u.val=contor(u);//获得康托展开哈希值
	 Queue que;
	 que.push(u);//将状态放入队列
	 mark[u.val]=1;//访问过了
	 while(!que.empty())//队列不为空
	 {
		  u=que.getfront();
		  que.pop();//每次将队首元素取出,判断它的三种变换状态是否已经访问过,若无访问则加入队列,并将其步数记为队首步数加一。
		  for(int i=0;i<3;i++)
		  {
			  v=u;
			  if(i==0)
			  {
				  FA(v);//上下翻转
				  v.val=contor(v);//康托展开
				  if(mark[v.val]==0)//未访问过
				  {
					  mark[v.val]=1;//标志为访问过
					  ans[v.val]=ans[u.val]+1;//并将其步数记为队首步数加一
					  que.push(v);//加入队列
				   }
			   }
			  else if(i==1)
			  {
				  FB(v);//循环移位
				  v.val=contor(v);
				  if(mark[v.val]==0)
				  {
					  mark[v.val]=1;
					  ans[v.val]=ans[u.val]+1;
					  que.push(v);
				   }
			   }
			  else
			  {
				  FC(v);//中部四元素逆时针旋转
				  v.val=contor(v);
				  if(mark[v.val]==0)
				  {
					  mark[v.val]=1;
					  ans[v.val]=ans[u.val]+1;
					  que.push(v);
				   }
			   }
		   }
	  }
 }
int main()
{
	bfs();//预处理
	int N,*as;//存储个数，每种状态的步骤数结果
	scanf("%d",&N);//输入拥有玩具个数
	as=(int *)malloc(sizeof(int)*N);
    for(int ii=0;ii<N;ii++)
	{
		for(int j=0;j<8;j++)//输入状态
		{
			scanf("%d",&s.a[j]);
		 }
		as[ii]=ans[contor(s)];//返回操作步数
    }
	for(int k=0;k<N;k++)//输出
	{
		printf("%d\n",as[k]);
	}
	return 0;
}

