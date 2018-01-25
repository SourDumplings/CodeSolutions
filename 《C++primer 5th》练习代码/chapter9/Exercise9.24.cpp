/*
 @Date    : 2017-12-24 10:54:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p348
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4};
    // vector<int> v;
    int i1 = v.front();
    int i2 = *(v.begin());
    int i3 = v[0];
    int i4 = v.at(0);
    printf("%d %d %d %d\n", i1, i2, i3, i4);
    // printf("%d %d %d\n", i1, i2, i4);
    return 0;
}
