/*
 @Date    : 2017-12-25 10:32:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p369
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
    vector<string> vi{"1", "10", "5"}, vd{"1.1", "2", "0.6"};
    int sumi = 0;
    double sumd = 0;
    for (const auto &i : vi)
    {
        sumi += stoi(i);
    }
    for (const auto &d : vd)
    {
        sumd += stod(d);
    }
    cout << sumi << endl;
    cout << sumd << endl;
    return 0;
}
