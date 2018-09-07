/*
 @Date    : 2018-03-14 09:13:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/842
所谓sibling指的是有共同的父母的亲兄弟姐妹
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <set>

using namespace std;

struct Person
{
    string name;
    set<string> parents;
};

static int N, M;
static vector<string> family;
static unordered_map<string, shared_ptr<Person>> nameData;
static unordered_map<string, int> spaceData;

void get_relations(int pSpace, int pPos, const string &parent)
{
    // printf("We want to get relations for %s\n", family[pPos].c_str());
    shared_ptr<Person> p = nameData[family[pPos]];
    if (p == nullptr)
    {
        p = make_shared<Person>();
        p->name = family[pPos];
        nameData[p->name] = p;
    }
    if (parent != "")
    {
        p->parents.insert(parent);
        // printf("%s gets a parent %s\n", p->name.c_str(), parent.c_str());
    }
    for (int i = pPos + 1; i != N && spaceData[family[i]] != pSpace; ++i)
    {
        if (spaceData[family[i]] == pSpace + 2)
            get_relations(pSpace+2, i, p->name);
    }
    return;
}

bool find_ancestor(const string &d, const string &a)
{
    if (nameData[d]->parents.empty())
        return false;
    if (nameData[d]->parents.find(a) != nameData[d]->parents.end())
        return true;
    else
    {
        for (const string &eachP : nameData[d]->parents)
        {
            if (find_ancestor(eachP, a))
                return true;
        }
        return false;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &N, &M);
    for (int i = 0; i != N; ++i)
    {
        string temp;
        getline(cin, temp);
        // printf("temp = \"%s\"\n", temp.c_str());
        int l = temp.length();
        int space = 0;
        for (int j = 0; j != l; ++j)
        {
            if (temp[j] != ' ')
            {
                family.push_back(std::move(temp).substr(j));
                // printf("we get a name %s and space %d\n", family.back().c_str(), space);
                spaceData[family.back()] = space;
                break;
            }
            else
                ++space;
        }
    }
    get_relations(0, 0, "");

    // for (auto &member : nameData)
    // {
    //     putchar('\n');
    //     printf("%s has parents: ", member.first.c_str());
    //     for (auto &p : member.second->parents)
    //         cout << p << ' ';
    //     cout << endl;
    // }

    for (int i = 0; i != M; ++i)
    {
        string name1, relation, name2;
        string temp;
        cin >> name1;
        cin >> temp;
        cin >> temp;
        cin >> relation;
        cin >> temp;
        cin >> name2;
        // printf("name1: %s relation: %s name2: %s\n", name1.c_str(), relation.c_str(),
            // name2.c_str());
        bool ok = false;
        switch (relation[0])
        {
            case 'c':
            {
                ok = nameData[name1]->parents.find(name2) != nameData[name1]->parents.end();
                break;
            }
            case 'p':
            {
                ok = nameData[name2]->parents.find(name1) != nameData[name2]->parents.end();
                break;
            }
            case 's':
            {
                for (const auto &p : nameData[name1]->parents)
                {
                    if (nameData[name2]->parents.find(p) != nameData[name2]->parents.end())
                    {
                        ok = true;
                        break;
                    }
                }
                break;
            }
            case 'a':
            {
                ok = find_ancestor(name2, name1);
                break;
            }
            case 'd':
            {
                ok = find_ancestor(name1, name2);
                break;
            }
        }
        if (ok) printf("True\n");
        else printf("False\n");
    }
    return 0;
}

