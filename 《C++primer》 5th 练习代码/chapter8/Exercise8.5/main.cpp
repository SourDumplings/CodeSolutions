/*
 @Date    : 2017-12-22 16:38:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p319
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("data");
    if (!in)
    {
        cerr << "can't open that file" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while(getline(in, line))
    {
        words.push_back(line);
    }

    in.close();

    for (auto word : words)
    {
        cout << word << endl;
    }
    return 0;
}
