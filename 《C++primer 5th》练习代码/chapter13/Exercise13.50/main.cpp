/*
 @Date    : 2018-01-04 16:56:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p544
 */

#include <iostream>
#include <vector>
#include "String.h"
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "construction" << endl;
    String s1("One"), s2("Two");
    String s3(s2);
    s3 = s1;
    s3 = String("Three");
    cout << "construction finished" << endl;

    vector<String> v;
    cout << endl;
    cout << "push_back of s1" << endl;
    v.push_back(s1);
    cout << endl;
    cout << "push_back of s2, called move" << endl;
    v.push_back(std::move(s2));
    // cout << "push_back of s2" << endl;
    // v.push_back(s2);
    cout << endl;
    cout << "push_back of Three" << endl;
    v.push_back(String("Three"));
    cout << endl;
    cout << "push_back of Four" << endl;
    v.push_back("Four");
    cout << endl;

    cout << "members of v:" << endl;
    for_each(v.begin(), v.end(), [] (const String &s) { s.getStr(cout); cout << endl; });

    return 0;
}
