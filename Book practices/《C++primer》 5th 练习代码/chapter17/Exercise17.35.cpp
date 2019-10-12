/*
 @Date    : 2018-01-18 14:55:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p760
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << uppercase;
    cout << "default format: " << 100 * sqrt(2.0) << '\n'
    << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
    << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n';
    // << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
    // << "use default: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";
    return 0;
}
