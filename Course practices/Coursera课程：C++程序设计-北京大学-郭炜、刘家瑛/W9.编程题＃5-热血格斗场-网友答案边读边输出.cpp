#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
map<int,int>::iterator iter,now,pre,nex;
int main()
{
    int n,x,y;
    cin>>n;
    m[1000000000] = 1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&x,&y);
        m[y]=x;
        iter=m.find(y);
        if(iter==m.begin())
        {
            nex = iter;
            nex++;
            printf("%d %d\n",iter->second,nex->second);
        }
        else if(iter==m.end())
        {
            pre=iter;
            pre--;
            printf("%d %d\n",iter->second,pre->second);
        }
        else
        {
            nex=iter;
            nex++;
            pre = iter;
            pre--;
            if(iter->first - pre->first < nex->first-iter->first) printf("%d %d\n",iter->second,pre->second);
            else if(iter->first-pre->first > nex->first-iter->first) printf("%d %d\n",iter->second,nex->second);
            else printf("%d %d\n",iter->second,pre->second);
        }
    }
    return 0;
}
