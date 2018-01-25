/*
 @Date    : 2017-12-22 19:34:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p322
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin("sstreamdata");
    vector<string> v;
    string line, word;
    while (getline(fin, line))
    {
        v.push_back(line);
    }
    for (auto line : v)
    {
        istringstream l(line);
        while (l >> word)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
