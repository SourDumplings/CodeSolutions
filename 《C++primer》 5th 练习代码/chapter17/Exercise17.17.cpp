/*
 @Date    : 2018-01-17 11:43:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p737
输出结果，感觉有问题：
rejeipt
freind
theif
ceive
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    smatch results;
    string file("rejeipt receipt freind theif receive");
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
        cout << it->str() << endl;

    return 0;
}
