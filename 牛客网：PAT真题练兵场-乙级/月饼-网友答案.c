#include<stdlib.h>
#include <stdio.h>
void Swap(int *A,int *B);
void Swap_double(double *A,double *B);
void Bulble_Sort(double A[],int B[],int N);
int main()
{
    int N,D,i,sum=0,last,flag=0;/*sum--所有库存全部卖出的品种的总库存，last--部分售出的月饼总类的标记*/
    double result=0;/*result--售出月饼的总价值*/
    scanf("%d %d",&N,&D);
    int stock[N],summary[N],key[N];/*用key数组记录排序以后原来的序号*/
    double price[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&stock[i]);
        key[i]=i;
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&summary[i]);
        price[i]=summary[i]/(double)stock[i];
    }
    Bulble_Sort(price,key,N);
    for(i=N-1;i>=0;i--)
    {
        sum+=stock[key[i]];
        if(sum>D)
        {
            sum-=stock[key[i]];
            last=i;
            flag=1;/*判断是否所有品种都卖完后都达不到市场需求*/
            break;
        }
    }
    if(flag==0)
    {
        for(i=0;i<N;i++)
        {
            result+=summary[i];
        }
    }else{
        for(i=i+1;i<N;i++)
        {
            result+=summary[key[i]];
        }
        result+=price[last]*(D-sum);
    }

    printf("%.2f\n",result);

    return 0;
}
void Swap(int *A,int *B)
{
    int temp=*A;
    *A=*B;
    *B=temp;
}
void Swap_double(double *A,double *B)
{
    double temp=*A;
    *A=*B;
    *B=temp;
}
void Bulble_Sort(double A[],int B[],int N)
{
    int i,j;
    for(j=N-1;j>=0;j--)
    {
        int flag=0;
        for(i=0;i<j;i++)
        {
            if(A[i]>A[i+1])
            {
                Swap_double(&A[i],&A[i+1]);
                Swap(&B[i],&B[i+1]);/*price Swap后，对应price的Key也进行Swap，然后通过来访问对应的stock[key[i]]*/
                flag=1;
            }
        }
        if(flag==0) break;
    }
}
