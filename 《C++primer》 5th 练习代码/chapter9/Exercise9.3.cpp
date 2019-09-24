/*
 @Date    : 2017-12-23 15:38:30
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

bool find(vector<int> v, int i)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it)
    {
        if (*it == i)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    int i;
    cin >> i;
    if (find(v, i))
    {
        cout << "find it" << endl;
    }
    else
    {
        cout << "cannot find it" << endl;
    }

    return 0;
}
