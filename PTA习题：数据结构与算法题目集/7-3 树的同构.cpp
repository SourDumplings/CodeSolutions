/*
 @Date    : 2018-03-11 09:29:26
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/711
 */

#include <iostream>
#include <cstdio>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

struct TreeNode
{
    char c;
    int left = -1, right = -1;
    int depth = 0;
    TreeNode(int c_, char l_, char r_): c(c_)
    {
        if (l_ == '-') left = -1;
        else left = l_ - '0';
        if (r_ == '-') right = -1;
        else right = r_ - '0';
    }
};

static const int MAXN = 11;
static shared_ptr<TreeNode> data1[MAXN], data2[MAXN];
static unordered_map<char, int> m2;

bool judge()
{
    for (int i = 0; i != MAXN; ++i)
    {
        if (data1[i])
        {
            set<char> children1, children2;
            int c = data1[i]->c;
            int l1 = data1[i]->left;
            if (l1 != -1) children1.insert(data1[l1]->c);
            else children1.insert('-');
            int r1 = data1[i]->right;
            if (r1 != -1) children1.insert(data1[r1]->c);
            else children1.insert('-');

            if (m2.find(c) == m2.end()) return false;
            int i2 = m2[c];
            int l2 = data2[i2]->left;
            if (l2 != -1) children2.insert(data2[l2]->c);
            else children2.insert('-');
            int r2 = data2[i2]->right;
            if (r2 != -1) children2.insert(data2[r2]->c);
            else children2.insert('-');

            if (children1 != children2) return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    fill(data1, data1+MAXN, nullptr);
    fill(data2, data2+MAXN, nullptr);
    int N1, N2;
    scanf("%d", &N1);
    for (int i = 0; i != N1; ++i)
    {
        char c, l, r;
        getchar();
        scanf("%c %c %c", &c, &l, &r);
        data1[i] = make_shared<TreeNode>(c, l, r);
    }
    scanf("%d", &N2);
    for (int i = 0; i != N2; ++i)
    {
        char c, l, r;
        getchar();
        scanf("%c %c %c", &c, &l, &r);
        data2[i] = make_shared<TreeNode>(c, l, r);
        m2.insert(make_pair(c, i));
    }
    if (N1 != N2)
        printf("No\n");
    else
    {
        if (judge())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

