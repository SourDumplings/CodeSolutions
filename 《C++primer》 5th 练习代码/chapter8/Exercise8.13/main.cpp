/*
 @Date    : 2017-12-22 20:13:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p323
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
    fstream fin("persondata");
    while (getline(fin, line))
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

    for (const auto &p : people)
    {
        cout << p.name;
        for (const auto &phonenum : p.phones)
        {
            cout << " " << phonenum;
        }
        cout << endl;
    }
    return 0;
}
