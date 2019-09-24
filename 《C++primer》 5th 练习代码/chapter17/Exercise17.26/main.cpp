/*
 @Date    : 2017-12-22 20:13:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p744
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const smatch &m)
{
    if (m[1].matched)
        return m[3].matched &&
               (m[4].matched == false || m[4].str() == " ");
    else
        return !m[3].matched &&
               (m[4].str() == m[6].str());
}

string format(const string &s) { return s; }

vector<PersonInfo> getData(ifstream &is)
{
    string phone = "(\\()?(\\d{3})(\\))?([ .-])?(\\d{3})([ -.])?(\\d{4})";
    regex r(phone);
    smatch m;
    string line, word;
    vector<PersonInfo> people;
    while (getline(is, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        getline(record, line);
        sregex_iterator it(line.begin(), line.end(), r), end_it;
        for (++it; it != end_it; ++it)
        {
            if (valid(*it))
                info.phones.push_back("V" + it->str());
            else
                info.phones.push_back("I" + it->str());
        }
        people.push_back(info);
    }
    return people;
}

int main(int argc, char const *argv[])
{
    ifstream fin("phones");
    ofstream fout("results");
    vector<PersonInfo> people = getData(fin);
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (nums[0] == 'I')
                badNums << " " << nums.substr(1) << endl;
            else
                formatted << " " << format(nums.substr(1)) << endl;
        }
        if (badNums.str().empty())
            fout << entry.name << endl << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s) " <<
                 badNums.str() << endl;
    }
    return 0;
}
