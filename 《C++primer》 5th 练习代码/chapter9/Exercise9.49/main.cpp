/*
 @Date    : 2017-12-24 20:55:22
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p367
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
    ifstream inf("data");
    string word;
    string chars = "dfpg";
    unsigned maxl = 0;
    string longestword = "no match words";
    while (getline(inf, word))
    {
        if (word.find_first_of(chars) == string::npos && word.size() > maxl)
        {
            maxl = word.size();
            longestword = word;
        }
    }
    cout << longestword << endl;
    return 0;
}
