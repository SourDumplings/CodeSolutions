/*
 @Date    : 2018-01-30 08:57:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/14/problems/44932
 */

#include <iostream>
using namespace std;

#define MAXLEN 50
typedef int KeyType;

typedef  struct
{ KeyType  key;
} elementType;

typedef  struct
{ elementType   data[MAXLEN+1];
  int   len;
} SeqList;

void creat(SeqList &L)
{ int i;
  cin>>L.len;
  for(i=1;i<=L.len;i++)
     cin>>L.data[i].key;
}

int  binSearch(SeqList T, KeyType k);

int main ()
{  SeqList L;  KeyType k;
   creat(L);
   cin>>k;
   int pos=binSearch(L,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* 请在这里填写答案 */
int binSearch(SeqList T, KeyType k)
{
    int lo = 1, hi = T.len;
    int mi;
    while (hi - lo > 1)
    {
        mi = (lo + hi) >> 1;
        k < T.data[mi].key ? hi = mi : lo = mi;
    }
    return k == T.data[lo].key ? lo : 0;
}
