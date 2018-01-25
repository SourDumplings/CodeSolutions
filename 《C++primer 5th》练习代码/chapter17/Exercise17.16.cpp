/*
 @Date    : 2018-01-17 10:10:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p734
测试：
freind
rei is okay
recept
recept is not okay
receipt
receipt is not okay
rejeipt
jei is okay
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
    regex r(pattern);
    smatch results;
    string word;
    while (cin >> word)
    {
        if (regex_search(word, results, r))
            cout << results.str() << " is okay" << endl;
        else
            cout << word << " is not okay" << endl;
    }
    return 0;
}
