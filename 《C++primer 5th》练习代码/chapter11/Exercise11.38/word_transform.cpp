/*
 @Date    : 2017-12-29 11:55:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p446
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

using namespace std;
using namespace std::placeholders;

unordered_map<string, string> build_map(ifstream &map_file)
{
    unordered_map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
        {
            trans_map[key] = value.substr(1);
        }
        else
        {
            throw runtime_error("No rule for " + key);
        }
    }
    return trans_map;
}

const string& transform(string &word, unordered_map<string, string> &trans_map)
{
    auto map_it = trans_map.find(word);
    if (map_it == trans_map.cend())
    {
        return word;
    }
    else
    {
        return map_it->second;
    }
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = build_map(map_file);
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    ifstream text("text"), rules("rules");
    word_transform(rules, text);
    return 0;
}
