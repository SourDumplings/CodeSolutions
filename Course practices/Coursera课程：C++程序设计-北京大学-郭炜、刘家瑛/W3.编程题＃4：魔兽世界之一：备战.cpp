/*
 @Date    : 2017-12-31 19:24:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/B/
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
#include <memory>
#include <new>

#define ERROR 99999

using namespace std;
using namespace std::placeholders;

const unsigned worriorNum = 5;

class Worrior
{
public:
    string& getName() { return name; }
    unsigned& getBornHp() { return bornHp; }
private:
    string name;
    unsigned bornHp;
};

array<Worrior, worriorNum> worriors;

class Headquarter
{
public:
    void produceWorriors(unsigned);
    Headquarter(string, const array<int, worriorNum>&);
    unsigned& getTotalHp() { return totalHp; }
    bool stop = false; // 是否已经停止制造英雄
    void reset();
    unsigned totalworriors = 0;
private:
    string name;
    unsigned totalHp;
    array<unsigned, worriorNum> bornSeq; // 记录了英雄的出生顺序的下标
    array<unsigned, worriorNum> eachNum; // 记录了每种英雄的个数
    unsigned lastWorrior = worriorNum - 1; // 记录了上一个出生的英雄在出生顺序中的下标
    unsigned NextWorriorAvail();
};

inline unsigned Headquarter::NextWorriorAvail()
{
    unsigned checked = 0;
    unsigned thisWorrior;
    for (thisWorrior = (lastWorrior + 1) % worriorNum;
        checked != worriorNum; thisWorrior = (thisWorrior + 1) % worriorNum)
    {
        if (totalHp >= worriors[bornSeq[thisWorrior]].getBornHp())
            return thisWorrior;
        else
            ++checked;
    }
    return ERROR;
}

inline Headquarter::Headquarter(string n, const array<int, worriorNum>& seq)
{
    name = n;
    fill(eachNum.begin(), eachNum.end(), 0);
    copy(seq.begin(), seq.end(), bornSeq.begin());
}

inline void Headquarter::reset(void)
{
    totalHp = 0;
    lastWorrior = worriorNum - 1;
    fill(eachNum.begin(), eachNum.end(), 0);
    totalworriors = 0;
    stop = false;
    return;
}

inline void Headquarter::produceWorriors(unsigned nowtime)
{
    if (!stop)
    {
        unsigned thisWorrior = NextWorriorAvail();
        if (thisWorrior == ERROR)
        {
            printf("%03d ", nowtime);
            cout << name << " headquarter stops making warriors" << endl;
            stop = true;
        }
        else
        {
            totalHp -= worriors[bornSeq[thisWorrior]].getBornHp();
            lastWorrior = thisWorrior;
            ++totalworriors;
            ++eachNum[bornSeq[thisWorrior]];

            printf("%03d ", nowtime);
            cout << name << " " << worriors[bornSeq[thisWorrior]].getName() << " " <<
            totalworriors << " born with strength " <<
            worriors[bornSeq[thisWorrior]].getBornHp() << "," << eachNum[bornSeq[thisWorrior]] << " "
            << worriors[bornSeq[thisWorrior]].getName() << " in " << name << " headquarter" << endl;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    Headquarter red("red", {2, 3, 4, 1, 0}), blue("blue", {3, 0, 1, 2, 4});
    array<string, worriorNum> names{{"dragon", "ninja", "iceman", "lion", "wolf"}};
    array<unsigned, worriorNum> bornHp;
    unsigned n;
    cin >> n;

    for (unsigned i = 0; i != worriorNum; ++i)
    {
        worriors[i].getName() = names[i];
    }

    for (unsigned c = 0; c != n; ++c)
    {
        unsigned borntotalHp;
        cin >> borntotalHp;
        blue.getTotalHp() = red.getTotalHp() = borntotalHp;
        for (unsigned i = 0; i != worriorNum; ++i)
        {
            cin >> bornHp[i];
        }
        for (unsigned i = 0; i != worriorNum; ++i)
        {
            worriors[i].getBornHp() = bornHp[i];
        }
        cout << "Case:" << c + 1 << endl;
        for (unsigned nowtime = 0; !(red.stop && blue.stop); ++nowtime)
        {
            red.produceWorriors(nowtime);
            blue.produceWorriors(nowtime);
        }
        red.reset();
        blue.reset();
    }
    return 0;
}
