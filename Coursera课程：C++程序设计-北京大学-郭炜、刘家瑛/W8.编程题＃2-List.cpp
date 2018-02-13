/*
 @Date    : 2018-02-04 16:32:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/S/
 */

#include <cstdio>
#include <algorithm>
// #include <array>
#include <list>
// #include <memory>

using namespace std;

list<int> *data[10000];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    // array<shared_ptr<list<int>>, 10000> data;
    char order[100];
    while (n--)
    {
        scanf("%s", order);
        switch (order[0])
        {
            case 'n':
            {
                int id;
                scanf("%d", &id);
                data[id] = new list<int>;
                // data[id] = make_shared<list<int>>();
                break;
            }
            case 'a':
            {
                int id, num;
                scanf("%d %d", &id, &num);
                data[id]->push_back(num);
                break;
            }
            case 'o':
            {
                int id;
                scanf("%d", &id);
                data[id]->sort();
                // for_each(data[id]->begin(), data[id]->end(),
                //     [] (const int i) { cout << i << " "; });
                int output = 0;
                for (auto it = data[id]->begin(); it != data[id]->end(); ++it)
                {
                    if (output++)
                        putchar(' ');
                    printf("%d", *it);
                }
                putchar('\n');
                break;
            }
            case 'm':
            {
                int id1, id2;
                scanf("%d %d", &id1, &id2);
                data[id1]->merge(*data[id2]);
                break;
            }
            case 'u':
            {
                int id;
                scanf("%d", &id);
                data[id]->sort();
                data[id]->unique();
                break;
            }
        }
    }
    for (int i = 0; i != 10000; ++i)
    {
        if (data[i])
            delete data[i];
    }
    return 0;
}
