/*
 @Date    : 2017-12-13 18:52:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p44
 */

#include <iostream>
#include <cstdio>

using namespace std;

string global_str;
int global_int;

int main()
{
    int local_int;
    string local_str;
    cout << global_int << "," << global_str << endl;
    cout << local_int << "," << local_str << endl;
    return 0;
}

