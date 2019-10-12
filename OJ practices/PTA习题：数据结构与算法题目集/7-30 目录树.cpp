/*
 @Date    : 2018-03-14 18:37:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/857
注意要先输出子目录再输出文件
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;

struct TNode
{
    string name;
    map<string, shared_ptr<TNode>> children;
    set<string> files;
    TNode(const string &name_): name(name_) {}
};

void build_tree(const string &childName, shared_ptr<TNode> &parent)
{
    // printf("processing %s\n", childName.c_str());
    int l = childName.length();
    if (l == 0) return;
    int flag = l;
    for (int i = 0; i != l; ++i)
    {
        if (childName[i] == '\\')
        {
            flag = i;
            break;
        }
    }
    if (flag == l)
        parent->files.insert(childName);
    else
    {
        shared_ptr<TNode> p = nullptr;
        if (parent->children.find(childName.substr(0, flag)) ==
            parent->children.end())
        {
            parent->children[childName.substr(0, flag)] =
            make_shared<TNode>(childName.substr(0, flag));
            // printf("get a %s's child %s\n", parent->name.c_str(),
                // parent->children[childName.substr(0, flag)]->name.c_str());
        }
        p = parent->children[childName.substr(0, flag)];
        build_tree(childName.substr(flag+1), p);
    }
    return;
}

void print(const shared_ptr<TNode> &root, int spaces)
{
    for (int i = 0; i != spaces; ++i) putchar(' ');
    cout << root->name << endl;
    for (auto &pC : root->children)
        print(pC.second, spaces + 2);
    for (auto &file : root->files)
    {
        for (int i = 0; i != spaces + 2; ++i) putchar(' ');
        cout << file << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d\n", &N);
    shared_ptr<TNode> root(new TNode("root"));
    while (N--)
    {
        string temp;
        getline(cin, temp);
        build_tree(temp, root);
    }
    print(root, 0);
    return 0;
}

