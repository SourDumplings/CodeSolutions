/*
 @Date    : 2017-12-15 18:44:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p110
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "Hi"};

    cout << v7.size() << endl;
    for (auto it = v7.cbegin(); it != v7.cend() && !it->empty(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
