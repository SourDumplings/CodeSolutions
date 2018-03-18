/*
 @Date    : 2018-01-30 13:49:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1056
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct P
{
    P(int w): W(w), rank(1) {}
    int W;
    int rank;
};

P* play(const vector<P*> &about_to_play)
{
    int max_W = 0;
    P* winner;

    // printf("Now playing: \n");
    // for (const auto &p : about_to_play)
    //     cout << p->W << " ";
    // putchar('\n');

    for (const auto &p : about_to_play)
    {
        if (p->W > max_W)
        {
            max_W = p->W;
            winner = p;
        }
    }
    return winner;
}

// int circles;

int main(int argc, char const *argv[])
{
    vector<P> data;
    queue<P*> survived;
    int NP, NG;
    scanf("%d %d", &NP, &NG);
    int Wi;
    for (int i = 0; i != NP; ++i)
    {
        scanf("%d", &Wi);
        data.push_back(P(Wi));
    }
    int temp;
    for (int i = 0; i != NP; ++i)
    {
        scanf("%d", &temp);
        survived.push(&data[temp]);
    }

    while (survived.size() > 1)
    {
        // ++circles;
        // printf("In the circle %d: \n", circles);

        queue<P*> next_to_play;
        queue<P*> loser;

        for (int played = 0; played != NP && !survived.empty();)
        {
            vector<P*> about_to_play;
            for (int poped = 0; poped != NG; ++poped)
            {
                if (survived.empty())
                    break;
                P* next_P = survived.front();
                survived.pop();
                about_to_play.push_back(next_P);
            }

            P* winner;
            winner = play(about_to_play);
            next_to_play.push(winner);
            played += about_to_play.size();
            for (auto &each_loser : about_to_play)
            {
                if (each_loser != winner)
                    loser.push(each_loser);
            }

            // printf("played = %d, NP = %d\n", played, NP);
        }

        while (!loser.empty())
        {
            loser.front()->rank += next_to_play.size();
            loser.pop();
        }

        while (!next_to_play.empty())
        {
            P* next_P = next_to_play.front();
            next_to_play.pop();
            survived.push(next_P);
        }

    }

    int output = 0;
    for (int i = 0; i != NP; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", data[i].rank);
    }
    putchar('\n');

    return 0;
}
