/*
 @Date    : 2018-01-15 13:03:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/E/
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <initializer_list>
#include <memory>

#define ERROR -1

using namespace std;

const int worriorNum = 5;
const int weaponNum = 3;
array<int, worriorNum> bornHp; // 按照dragon 、ninja、iceman、lion、wolf的顺序记录初始血量

class Weapon
{
public:
    Weapon(const string &n): name(n) {}
    string name;
};

class Sword: public Weapon
{
public:
    Sword(): Weapon("sword") {}
};

class Bomb: public Weapon
{
public:
    Bomb(): Weapon("bomb") {}
};

class Arrow: public Weapon
{
public:
    Arrow(): Weapon("arrow") {}
};

ostream& operator<<(ostream &os, Weapon &w)
{
    os << w.name;
    return os;
}

class Worrior
{
public:
    Worrior() = default;
    Worrior(const string &n, int b, int no): name(n), bornHp(b), n(no) {}
    const string& getName() const { return name; }
    const int getBornHp() const { return bornHp; }
    virtual void extraInfo() = 0;
    virtual ~Worrior() = default;
protected:
    string name;
    int bornHp;
    shared_ptr<Weapon> getAWeapon(int weaponNum)
    {
        switch (weaponNum)
        {
            case 0: return make_shared<Sword>(); break;
            case 1: return make_shared<Bomb>(); break;
            case 2: return make_shared<Arrow>(); break;
        }
    }
public:
    int n;
};

class Dragon: public Worrior
{
public:
    Dragon(int b, int n, int totalHp):
    Worrior("dragon", b, n), morale(static_cast<double>(totalHp) / bornHp) {}
    void extraInfo() override
    {
        cout << "It has a " << weapon->name << ",and it's morale is ";
        printf("%.2f\n", morale);
        return;
    }
private:
    shared_ptr<Weapon> weapon = getAWeapon(n%weaponNum);
    double morale;
};

class Ninja: public Worrior
{
public:
    Ninja(int b, int n): Worrior("ninja", b, n) {}
    void extraInfo() override
    {
        cout << "It has a "<< weapon1->name << " and a " << weapon2->name << endl;
    }
private:
    shared_ptr<Weapon> weapon1 = getAWeapon(n%weaponNum),
    weapon2 = getAWeapon((n+1)%weaponNum);
};

class Iceman: public Worrior
{
public:
    Iceman(int b, int n): Worrior("iceman", b, n) {}
    void extraInfo() override
    {
        cout << "It has a " << weapon->name << endl;
        return;
    }
private:
    shared_ptr<Weapon> weapon = getAWeapon(n%weaponNum);
};

class Lion: public Worrior
{
public:
    Lion(int b, int n, int totalHp): Worrior("lion", b, n), loyalty(totalHp) {}
    void extraInfo() override
    {
        cout << "It's loyalty is " << loyalty << endl;
        return;
    }
private:
    int loyalty;
};

class Wolf: public Worrior
{
public:
    Wolf(int b, int n): Worrior("wolf", b, n) {}
    void extraInfo() override
    {
        return;
    }
};

class Headquarter
{
public:
    void produceWorriors(int);
    Headquarter(string, const array<int, worriorNum>&);
    int& getTotalHp() { return totalHp; }
    bool stop = false; // 是否已经停止制造英雄
    void reset();
    int totalworriors = 0;
private:
    string name;
    int totalHp;
    array<int, worriorNum> bornSeq; // 记录了英雄的出生顺序的下标
    array<int, worriorNum> eachNum; // 记录了每种英雄的个数
    int lastWorrior = worriorNum - 1; // 记录了上一个出生的英雄在出生顺序中的下标
    int nextWorriorAvail();
    void produceAWorrior(int, int);
    void outPutInfo(Worrior&, int, int);
};

inline Headquarter::Headquarter(string n, const array<int, worriorNum>& seq)
{
    name = n;
    fill(eachNum.begin(), eachNum.end(), 0);
    copy(seq.begin(), seq.end(), bornSeq.begin());
}

inline int Headquarter::nextWorriorAvail()
{
    int checked = 0;
    int thisWorrior;
    for (thisWorrior = (lastWorrior + 1) % worriorNum;
        checked != worriorNum; thisWorrior = (thisWorrior + 1) % worriorNum)
    {
        if (totalHp >= bornHp[bornSeq[thisWorrior]])
            return thisWorrior;
        else
            ++checked;
    }
    return ERROR;
}

inline void Headquarter::outPutInfo(Worrior &w, int nowtime, int thisWorriorNum)
{
    printf("%03d ", nowtime);
    cout << name << " " << w.getName() << " " <<
    w.n << " born with strength " <<
    w.getBornHp() << "," << thisWorriorNum << " "
    << w.getName() << " in " << name << " headquarter" << endl;
    w.extraInfo();
    return;
}

inline void Headquarter::produceAWorrior(int thisWorrior, int nowtime)
{
    switch(bornSeq[thisWorrior])
    {
        case 0:
        {
            Dragon worrior(bornHp[0], totalworriors, totalHp);
            outPutInfo(worrior, nowtime, eachNum[0]);
            break;
        }
        case 1:
        {
            Ninja worrior(bornHp[1], totalworriors);
            outPutInfo(worrior, nowtime, eachNum[1]);
            break;
        }
        case 2:
        {
            Iceman worrior(bornHp[2], totalworriors);
            outPutInfo(worrior, nowtime, eachNum[2]);
            break;
        }
        case 3:
        {
            Lion worrior(bornHp[3], totalworriors, totalHp);
            outPutInfo(worrior, nowtime, eachNum[3]);
            break;
        }
        case 4:
        {
            Wolf worrior(bornHp[4], totalworriors);
            outPutInfo(worrior, nowtime, eachNum[4]);
            break;
        }
    }
    return;
}

inline void Headquarter::produceWorriors(int nowtime)
{
    if (!stop)
    {
        int thisWorrior = nextWorriorAvail();
        if (thisWorrior == ERROR)
        {
            printf("%03d ", nowtime);
            cout << name << " headquarter stops making warriors" << endl;
            stop = true;
        }
        else
        {
            totalHp -= bornHp[bornSeq[thisWorrior]];
            lastWorrior = thisWorrior;
            ++totalworriors;
            ++eachNum[bornSeq[thisWorrior]];
            produceAWorrior(thisWorrior, nowtime);
        }
    }
    return;
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



int main(int argc, char const *argv[])
{
    Headquarter red("red", {2, 3, 4, 1, 0}), blue("blue", {3, 0, 1, 2, 4});
    int n;
    cin >> n;

    for (int c = 0; c != n; ++c)
    {
        int borntotalHp;
        cin >> borntotalHp;
        blue.getTotalHp() = red.getTotalHp() = borntotalHp;
        for (int i = 0; i != worriorNum; ++i)
        {
            cin >> bornHp[i];
        }
        cout << "Case:" << c + 1 << endl;
        for (int nowtime = 0; !(red.stop && blue.stop); ++nowtime)
        {
            red.produceWorriors(nowtime);
            blue.produceWorriors(nowtime);
        }
        red.reset();
        blue.reset();
    }
    return 0;
}
