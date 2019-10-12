/*
 @Date    : 2018-01-11 11:11:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

template <typename T> int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}

int main(int argc, char const *argv[])
{
    cout << compare(1, 0) << endl;
    cout << compare("abc", "abs") << endl;
    cout << compare(string("abc"), string("abs")) << endl;
    cout << compare(vector<int>({1, 3}), vector<int>({1, 2})) << endl;
    cout << compare(set<int>({1}), set<int>({1, 2})) << endl;
    return 0;
}
