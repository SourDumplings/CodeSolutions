#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,j,n ;
    char a[10];
    char b[10]={'Y','Q','B','S','W','Q','B','S'};
    scanf("%s",a);
    for(i=8;i>=0;i--){
    if(a[i]>='0'&&a[i]<='9')
      {n=i;break;}
    }


    for(i=0;i<=n;i++)
        {
        j=8+i-n;
        if(a[i]>'0'&&a[i]<='9')
            {
                if(i!=n)printf("%c%c",a[i]+49,b[j]);
                else printf("%c",a[i]+49);
            }
        if(a[i]=='0')
        {
            if(a[i+1]>'0'&&a[i+1]<='9'&&j!=4)printf("%c",a[i]+49);
            if(j==4)printf("%c",b[j]);
        }
        }

 if(n==0&&a[0]=='0')
    {
    printf("a");
    }
    return 0;
}
