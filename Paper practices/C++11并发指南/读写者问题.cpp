/*
 @Date    : 2018-04-17 16:37:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
自己设计的一个读写者问题，用作练习吧
读写者问题简单地说就是一个写者写的时候不能有读者读也不能有别的写。
一个读者读的时候可以有别的读者读但不能有写者写。
多次运行结果如下：
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = hhh
size = 3, s = hhh
size = 3, s = hhh
size = 3, s = hhh
size = 3, s = hhh
size = 3, s = hhh
size = 3, s = hhh

size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh

size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = h

size = 1, s = h
size = 1, s = h
size = 1, s = h
size = 1, s = hhhhhhh
size = 7, s = hhhhhhh
size = 7, s = hhhhhhh
size = 7, s = hhhhhhh
size = 7, s = hhhhhhh
size = 7, s = hhhhhhh
size = 7, s = hhhhhhh

size = 1, s = h
size = 2, s = hh
size = 3, s = hhh
size = 4, s = hhhh
size = 5, s = hhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
size = 6, s = hhhhhh
 */

#include <iostream>
#include <cstdio>
#include <string>

#include <thread>
#include <mutex>

using namespace std;

struct Data
{
    int size = 1;
    string s = "h";
};

static mutex omtx, mtx;

void write_task(Data &data)
{
    mtx.lock();

    ++data.size;
    data.s += "h";

    mtx.unlock();

    return;
}

void read_task(Data &data)
{
    static int readersNum = 0;
    ++readersNum;

    if (readersNum == 1)
    {
        mtx.lock();
    }

    omtx.lock();
    printf("size = %d, s = %s\n", data.size, data.s.c_str());
    omtx.unlock();

    --readersNum;
    if (readersNum == 0)
    {
        mtx.unlock();
    }

    return;
}

int main(int argc, char const *argv[])
{
    thread readThreads[10], writeThreads[10];
    Data data;
    for (unsigned i = 0; i < 10; ++i)
    {
        readThreads[i] = std::move(thread(read_task, ref(data)));
        writeThreads[i] = std::move(thread(write_task, ref(data)));
    }

    for (unsigned i = 0; i < 10; ++i)
    {
        readThreads[i].join();
        writeThreads[i].join();
    }
    return 0;
}

