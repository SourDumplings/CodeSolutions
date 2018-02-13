/*
 @Date    : 2018-01-28 21:30:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/G/
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
    int num;
    cin >> num;
    cout << hex << num << endl << dec << setw(10) << setfill('0') << num << endl;
    return 0;
}
