/*
 @Date    : 2017-12-27 12:08:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p397
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
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 5;
    auto f = [i] () mutable -> bool {if (i > 0) {--i; return false;} else
        {return true;}};
    for (int j = 0; j < 10; ++j)
    {
        cout << f() << " ";
    }
    cout << endl;
    cout << "i = " << i << endl;
    return 0;
}
