/*
 @Date    : 2018-01-28 21:19:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/F/
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    double num;
    cin >> num;
    cout << setiosflags(ios::fixed) << setprecision(5) << num << endl
    << scientific << setprecision(7) << num << endl;
    return 0;
}
