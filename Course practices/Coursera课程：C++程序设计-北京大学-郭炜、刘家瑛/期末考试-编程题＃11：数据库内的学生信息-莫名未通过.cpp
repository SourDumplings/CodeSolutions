/*
 @Date    : 2018-02-13 13:41:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
程序填空，使得下面的程序,先输出

(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),

(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),

(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),

(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),

******

然后，再根据输入数据按要求产生输出数据
 */

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
template <typename Key, typename Value, typename Compare = greater<Key> >
class MyMultimap
{
private:
    multimap<Key, Value, Compare> data;
public:
    typedef typename map<Key, Value, Compare>::iterator iterator;
    void insert(const pair<Key, Value> &p) { data.insert(p); return; }
    typename map<Key, Value, Compare>::iterator begin() { return data.begin(); }
    typename map<Key, Value, Compare>::iterator end() { return data.end(); }
    void Set(const Key &k, const Value v)
    {
        int n = data.count(k);
        data.erase(k);
        while (n--)
            data.insert(make_pair(k, v));
        return;
    }
    void clear() { data.clear(); return; }
    typename map<Key, Value, Compare>::iterator find(const Key &k) { return data.find(k); }
};

template <typename Key, typename Value>
ostream& operator<<(ostream &os, const pair<Key, Value> &p)
{
    os << '(' << p.first << ' ' << p.second << ')';
    return os;
}


struct Student
{
        string name;
        int score;
};
template <class T>
void Print(T first,T last) {
        for(;first!= last; ++ first)
                cout << * first << ",";
        cout << endl;
}
int main()
{

        Student s[] = { {"Tom",80},{"Jack",70},
                                        {"Jone",90},{"Tom",70},{"Alice",100} };
        MyMultimap<string,int> mp;
        for(int i = 0; i<5; ++ i)
                mp.insert(make_pair(s[i].name,s[i].score));
        Print(mp.begin(),mp.end()); //按姓名从大到小输出

        mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
        Print(mp.begin(),mp.end());


        MyMultimap<int,string,less<int> > mp2;
        for(int i = 0; i<5; ++ i)
                mp2.insert(make_pair(s[i].score,s[i].name));

        Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
        mp2.Set(70,"Error");          //把所有成绩为70的学生，名字都改为"Error"
        Print(mp2.begin(),mp2.end());
        cout << "******" << endl;

        mp.clear();

        string name;
        string cmd;
        int score;
        while(cin >> cmd ) {
                if( cmd == "A") {
                        cin >> name >> score;
                        if(mp.find(name) != mp.end() ) {
                                cout << "erroe" << endl;
                        }
                        mp.insert(make_pair(name,score));
                }
                else if(cmd == "Q") {
                        cin >> name;
                        MyMultimap<string,int>::iterator p = mp.find(name);
                        if( p!= mp.end()) {
                                cout << p->second << endl;
                        }
                        else {
                                cout << "Not Found" << endl;
                        }
                }
        }
        return 0;
}
