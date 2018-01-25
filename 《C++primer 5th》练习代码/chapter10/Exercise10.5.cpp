/*
 @Date    : 2017-12-25 16:41:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p380
返回：
1
0
1
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

using namespace std;

int main(int argc, char const *argv[])
{
    char *p[] = {"I", "love", "you"};
    char *q[] = {"I", "love", "you"};
    char *s[] = {"I", "love", "yo"};
    char *r[] = {p[0], p[1], p[2]};
    cout << equal(begin(p), end(p), begin(q)) << endl;
    cout << equal(begin(p), end(p), begin(s)) << endl;
    cout << equal(begin(p), end(p), begin(r)) << endl;
    return 0;
}
