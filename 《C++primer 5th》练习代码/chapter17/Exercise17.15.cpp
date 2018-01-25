/*
 @Date    : 2018-01-17 09:45:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p734
感觉有问题，运行：
friend
friend is not okay
receive
ceive is okay
freind
freind is okay
receipt
ceipt is okay
rejeipt
rejeipt is okay

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
