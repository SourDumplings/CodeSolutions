/*
 @Date    : 2017-12-23 15:42:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p332
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator find(vector<int> &v, int i)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (*it == i)
        {
            return it;
        }
    }
    return v.end();
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    int i;
    cin >> i;
    if (find(v, i) != v.end())
    {
        cout << "find it" << endl;
    }
    else
    {
        cout << "cannot find it" << endl;
    }

    return 0;
}
