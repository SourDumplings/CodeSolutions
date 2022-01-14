/*
 * @Author: SourDumplings
 * @Date: 2022-01-14 14:27:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description:
 */

#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    struct
    {
        int *a;
        float b;
        char c;
        short d;
        long e;
        double f;
        int g;
        char *h;
    } rec;

    printf("sizeof(a) = %d, &a = %p\n", sizeof(rec.a), &rec.a);
    printf("sizeof(b) = %d, &b = %p\n", sizeof(rec.b), &rec.b);
    printf("sizeof(c) = %d, &c = %p\n", sizeof(rec.c), &rec.c);
    printf("sizeof(d) = %d, &d = %p\n", sizeof(rec.d), &rec.d);
    printf("sizeof(e) = %d, &e = %p\n", sizeof(rec.e), &rec.e);
    printf("sizeof(f) = %d, &f = %p\n", sizeof(rec.f), &rec.f);
    printf("sizeof(g) = %d, &g = %p\n", sizeof(rec.g), &rec.g);
    printf("sizeof(h) = %d, &h = %p\n", sizeof(rec.h), &rec.h);

    /* 
    输出：
    sizeof(a) = 8, &a = 0x7ffccf121240
    sizeof(b) = 4, &b = 0x7ffccf121248
    sizeof(c) = 1, &c = 0x7ffccf12124c
    sizeof(d) = 2, &d = 0x7ffccf12124e
    sizeof(e) = 8, &e = 0x7ffccf121250
    sizeof(f) = 8, &f = 0x7ffccf121258
    sizeof(g) = 4, &g = 0x7ffccf121260
    sizeof(h) = 8, &h = 0x7ffccf121268
     */
    return 0;
}
