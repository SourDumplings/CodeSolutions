/*
 @Date    : 2018-01-30 11:06:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1055
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(const tuple<string, int, int> &p1, const tuple<string, int, int> &p2)
{
    bool result;
    if (get<2>(p1) > get<2>(p2))
        result = true;
    else if (get<2>(p1) == get<2>(p2))
    {
        if (get<1>(p1) < get<1>(p2))
            result = true;
        else if (get<1>(p1) == get<1>(p2))
        {
            if (get<0>(p1) < get<0>(p2))
                result = true;
            else
                result = false;
        }
        else
            result = false;
    }
    else
        result = false;
    return result;
}

void OutPut(const vector<tuple<string, int, int>> &data, const int M,
    const int Amin, const int Amax)
{
    int output = 0;
    for (const auto &p : data)
    {
        if (get<1>(p) <= Amax && get<1>(p) >= Amin)
        {
            cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << endl;
            output++;
        }
        if (output == M)
            break;
    }
    if (!output)
        printf("None\n");
    return;
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    vector<tuple<string, int, int>> data;
    tuple<string, int, int> p;
    string name;
    int age, wealth;
    for (int i = 0; i != N; ++i)
    {
        cin >> name >> age >> wealth;
        data.push_back(make_tuple(name, age, wealth));
    }

    sort(data.begin(), data.end(), cmp);

    int M, Amin, Amax;
    int caseNum = 0;
    for (int i = 0; i != K; ++i)
    {
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", ++caseNum);
        OutPut(data, M, Amin, Amax);
    }
    return 0;
}
