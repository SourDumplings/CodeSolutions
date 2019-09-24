/*
 @Date    : 2018-01-18 10:15:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p753
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
#include <ctime>

using namespace std;

map<string, vector<string>> buildMap(ifstream &map_file)
{
    map<string, vector<string>> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() <= 1)
            throw runtime_error("no rule for "+key);
        else
        {
            istringstream value_s(value);
            string each_value;
            while (value_s >> each_value)
            {
                trans_map[key].push_back(each_value);
            }
        }
    }
    return trans_map;
}

const string& transform(const string &s, const map<string, vector<string>> &m)
{
    static default_random_engine e(time(0));
    auto map_it = m.find(s);
    if (map_it != m.cend())
    {
        uniform_int_distribution<unsigned> u(0, map_it->second.size()-1);
        return map_it->second[u(e)];
    }
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    cout << "Here is our transformation map: \n\n";
    for (auto entry : trans_map)
    {
        cout << "key: " << entry.first << "\tvalue: ";
        for (auto s : entry.second)
            cout << s << " ";
        cout << endl;
    }
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // if (argc != 3)
    //     throw runtime_error("wrong number of arguments");
    // ifstream map_file(argv[1]);
    // if (!map_file)
    //     throw runtime_error("no transformation file");
    // ifstream input(argv[2]);
    // if (!input)
    //     throw runtime_error("no input file");
    // else
    //     word_transform(map_file, input);
    string goon;
    do
    {
        ifstream map_file("rules"), input("text");
        word_transform(map_file, input);
        printf("continue?(y/n): ");
        cin >> goon;
    } while (goon[0] == 'Y' || goon[0] == 'y');
    return 0;
}
