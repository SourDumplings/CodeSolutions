/*
 @Date    : 2018-08-23 22:56:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int N, M;
map<string, set<string>> titleMap, authorMap, keywordsMap, publisherMap, yearMap;

void read_keywords(const string &keywords, const string &id)
{
    istringstream sin(keywords);
    string keyword;
    while (sin >> keyword)
    {
        keywordsMap[keyword].insert(id);
    }
    return;
}

void print_id(const set<string> &s)
{
    if (s.empty())
        printf("Not Found\n");
    else
    {
        for (auto id : s)
        {
            cout << id << endl;
        }
    }

    return;
}

int main()
{
    scanf("%d\n", &N);
    for (int i = 0; i != N; ++i)
    {
        string id;
        string title, author, keywords, publisher, year;
        getline(cin, id);
        getline(cin, title);
        titleMap[title].insert(id);
        getline(cin, author);
        authorMap[author].insert(id);
        getline(cin, keywords);
        read_keywords(keywords, id);
        getline(cin, publisher);
        publisherMap[publisher].insert(id);
        getline(cin, year);
        yearMap[year].insert(id);
    }

    scanf("%d\n", &M);
    for (int i = 0; i != M; ++i)
    {
        string sq;
        getline(cin, sq);
        cout << sq << endl;
        string info(sq.substr(3));
        switch (sq[0])
        {
            case '1' : print_id(titleMap[info]); break;
            case '2' : print_id(authorMap[info]); break;
            case '3' : print_id(keywordsMap[info]); break;
            case '4' : print_id(publisherMap[info]); break;
            case '5' : print_id(yearMap[info]); break;
        }
    }
    return 0;
}

