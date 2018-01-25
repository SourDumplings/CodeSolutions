/*
 @Date    : 2018-01-16 22:42:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p728
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

template <size_t N>
class exam
{
private:
    bitset<N> s;
public:
    exam(): s() {}
    size_t get_size() { return N; }
    void set_solution(size_t n, bool b) { s.set(n, b); }
    bitset<N> get_solution() const { return s; }
    size_t score(const bitset<N> &a);
};

template <size_t N>
size_t exam<N>:: score(const bitset<N> &a)
{
    size_t ret = 0;
    for (size_t i = 0; i < N; ++i)
    {
        if (s[i] == a[i])
            ++ret;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    exam<80> e;
    e.set_solution(0, 1);
    e.set_solution(79, 1);
    cout << e.get_solution() << endl;

    bitset<80> a;
    cout << e.get_size() << " questions, " <<
    e.score(a) << (e.score(a) > 1 ? " questions corect" : " question corects") << endl;
    return 0;
}
