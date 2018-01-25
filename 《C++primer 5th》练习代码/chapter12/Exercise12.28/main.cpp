/*
 @Date    : 2018-01-01 21:39:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p487
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
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

using line_no = vector<string>::size_type;
vector<string> file;
map<string, set<line_no>> wm;

string cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
    {
        if (!ispunct(*it))
        {
            ret += tolower(*it);
        }
    }
    return ret;
}

ostream& query_and_print(const string &sought, ostream &os)
{
    auto loc = wm.find(sought);
    if (loc == wm.end())
    {
        os << sought << " doesn't occur" << endl;
    }
    else
    {
        auto lines = loc->second;
        os << sought << " occurs " << lines.size() <<
         ((lines.size() > 1) ? " times" : " time") << endl;
         for (auto num : lines)
         {
            os << "\t(No." << num + 1 << " line) "
            << *(file.begin() + num) << endl;
         }
    }
    return os;
}

void input_text(ifstream &infile)
{
    string text;
    while (getline(infile, text))
    {
        file.push_back(text);
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            wm[cleanup_str(word)].insert(n);
        }
    }
    return;
}

void runQueries(ifstream &infile)
{
    input_text(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        query_and_print(s, cout) << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    ifstream infile("storyDataFile");
    // ifstream infile;
    // if (argc < 2 || !(infile.open(argv[1]), infile))
    // {
    //     cerr << "No input file!" << endl;
    //     return EXIT_FAILURE;
    // }
    runQueries(infile);
    return 0;
}
