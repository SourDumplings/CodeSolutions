#include<stdio.h>
#include<string.h>

int main()
{
    int a[100010][3]={0},temp[3]={0},i,j=0,staraddr,backnum,max,findaddr,count=0;
    scanf("%d %d %d",&staraddr,&max,&backnum);
    for(i=0;i<max;i++)
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    findaddr=staraddr;
    for(i=0;i<max;i++)                                     //先按照顺序排好链表
    {
        j=i;
        while(a[j][0]!=findaddr && findaddr!=-1) j++;
        if(a[j][0]==findaddr)
        {
            memcpy(temp,a[j],3*sizeof(int));
            memcpy(a[j],a[i],3*sizeof(int));
            memcpy(a[i],temp,3*sizeof(int));
            findaddr=a[i][2];
        }
        if(findaddr==-1)
        {
            max=i+1; // 这样是得到了真正的在链表上的结点数
            break;
        }
    }
    // count为开始反转的第一个结点的位置
    while(count+backnum<=max && max!=0)                        //按照反转要求重新排序
    {
        for(i=count,j=count+backnum-1;i<j;i++,j--)
        {
            memcpy(temp,a[i],3*sizeof(int));
            memcpy(a[i],a[j],3*sizeof(int));
            memcpy(a[j],temp,3*sizeof(int));
        }
        count+=backnum;
    }
    for(i=0;i<max-1;i++)                     //修改反转之后链表的关系
        a[i][2]=a[i+1][0];
    for(i=0;i<max-1 && a[i][2]!=-1;i++)
    {
        printf("%05d %d %05d\n",a[i][0],a[i][1],a[i][2]);
    }

    printf("%05d %d -1",a[i][0],a[i][1]);
    putchar('\n');
    return 0;
}
