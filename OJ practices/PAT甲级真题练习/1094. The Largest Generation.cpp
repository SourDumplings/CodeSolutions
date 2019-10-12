/*
 @Date    : 2018-02-18 22:31:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1094
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>

using namespace std;

struct Person { vector<int> children; };

static const int MAXN = 101;
static array<shared_ptr<Person>, MAXN> family;
static array<int, MAXN> levelData;

void get_level(int parent, int plevel)
{
    if (family[parent] == nullptr)
        return;
    int cNum = family[parent]->children.size();
    for (int i = 0; i != cNum; ++i)
    {
        int cId = family[parent]->children[i];
        ++levelData[plevel + 1];
        get_level(cId, plevel + 1);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    int id, K, c;
    for (int i = 0; i != M; ++i)
    {
        scanf("%d %d", &id, &K);
        shared_ptr<Person> p(new Person);
        family[id] = p;
        for (int j = 0; j != K; ++j)
        {
            scanf("%d", &c);
            family[id]->children.push_back(c);
        }
    }
    fill(levelData.begin(), levelData.end(), 0);
    levelData[1] = 1;
    get_level(1, 1);
    int maxGenerationNum, maxGenerationLevel;
    for (int i = 1; i != N + 1; ++i)
    {
        int thisLevelNum = levelData[i];
        if (thisLevelNum != 0)
        {
            if (thisLevelNum > maxGenerationNum)
            {
                maxGenerationNum = thisLevelNum;
                maxGenerationLevel = i;
            }
        }
        else
            break;
    }
    printf("%d %d", maxGenerationNum, maxGenerationLevel);
    return 0;
}
