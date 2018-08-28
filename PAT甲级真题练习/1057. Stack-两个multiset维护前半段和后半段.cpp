/*
 @Date    : 2018-08-28 21:34:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
 */


//两个multiset的思路：
//来自：https://blog.csdn.net/kakitgogogo/article/details/51926600
//模拟stack，不过这里的stack加多一个功能，就是输出中位数。用一个stack数据结构来模拟栈的功能，
//而为了方便得到中位数，要同时维护两个multiset数据结构（因为值可以重复，所以要用multiset）。
//一个set储存前一半的数（设为s1），一个set储存后一半的数（设为s2），
//这里s1的大小要和s2的大小一样或比s2的大小大1。同时更新中位数值mid，mid就是s1的最后一个数。
//在push的时候，把值push到stack中，同时，如果push的值小于等于mid就插入到s1，否则插入到s2，
//最后为了使他们的大小符合上面的描述，所以要调整一下，更新s1，s2和mid。
//pop的时候，对stack进行pop操作，同时，如果pop出来的值小于等于mid，
//就在s1中找出该值然后删除，否则在s2中找出该值然后删除，当前最后也要调整一下，更新s1，
//s2和mid。最后找中位数就直接找就行了。这里要注意的是multiset删除操作中，不能用实值作为参数，
//因为这样会把所有的这个值都删去，这里要先用find函数找出其中一个然后再删除。


#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int N;
multiset<int> s1, s2;
int mid = 100005;
stack<int> S;

void adjust()
{
    if (s2.size() + 1 < s1.size())
    {
        s1.erase(s1.find(mid));
        s2.insert(mid);
    }
    else if (s1.size() < s2.size())
    {
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }
    if (s1.empty())
        mid = 100005;
    else
        mid = *s1.rbegin();
    return;
}

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        string order;
        cin >> order;
        switch (order[1])
        {
        case 'o':
            {
                if (S.empty())
                {
                    printf("Invalid\n");
                }
                else
                {
                    int p = S.top();
                    printf("%d\n", p);
                    S.pop();
                    if (p <= mid)
                    {
                        auto it = s1.find(p);
                        if (it != s1.end())
                        {
                            s1.erase(it);
                            adjust();
                        }
                    }
                    else
                    {
                        auto it = s2.find(p);
                        if (it != s2.end())
                        {
                            s2.erase(it);
                            adjust();
                        }
                    }
                }
                break;
            }
        case 'e':
            {
                if (S.empty())
                    printf("Invalid\n");
                else
                    printf("%d\n", mid);
                break;
            }
        case 'u':
            {
                int p;
                scanf("%d", &p);
                S.push(p);
                if (p <= mid)
                {
                    s1.insert(p);
                    adjust();
                }
                else
                {
                    s2.insert(p);
                    adjust();
                }
                break;
            }
        }
    }

    return 0;
}
