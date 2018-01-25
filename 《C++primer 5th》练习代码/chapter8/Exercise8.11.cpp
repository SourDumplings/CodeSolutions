/*
 @Date    : 2017-12-22 19:45:52
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
#include <fstream>
#include <sstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(int argc, char const *argv[])
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear(); // 重复使用字符串流时，每次使用都要调用clear()
        record.str(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    return 0;
}
