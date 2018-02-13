/*
 @Date    : 2018-02-10 15:43:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/T/
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void my_add(multiset<int> &data, map<int, bool> &record, int num)
{
    data.insert(num);
    record[num] = true;
    printf("%d\n", data.count(num));
    return;
}

void my_del(multiset<int> &data, int num)
{
    printf("%d\n", data.count(num));
    data.erase(num);
    return;
}

void my_ask(const multiset<int> &data, map<int, bool> &record, int num)
{
    cout << record[num] << ' ' << data.count(num) << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char order[10];
    int num;
    multiset<int> data;
    map<int, bool> record;
    while (n--)
    {
        scanf("%s %d", order, &num);
        switch (order[1])
        {
            case 'e': my_del(data, num); break;
            case 's': my_ask(data, record, num); break;
            case 'd': my_add(data, record, num); break;
        }
    }
    return 0;
}
