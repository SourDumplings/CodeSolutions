/*
 @Date    : 2018-03-15 17:03:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/890
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MAXN = 2002;
static int N, P;
static char hashTable[MAXN][9];

static int output = 0;

int my_hash(char s[])
{
    int l = strlen(s);
    int res = 0;
    if (l > 0)
        res += s[l-1] - 'A';
    if (l > 1)
        res += 32 * (s[l-2] - 'A');
    if (l > 2)
        res += 32 * 32 * (s[l-3] - 'A');
    return res;
}

int my_find(char s[])
{
    int h = my_hash(s);
    int p = -1;
    for (int i = 0;; ++i)
    {
        if (hashTable[(h+i*i)%P][0] == '\0' || strcmp(hashTable[(h+i*i)%P], s) == 0)
        {
            p = (h + i * i) % P;
            break;
        }
        if (hashTable[(h-i*i)%P][0] == '\0' || strcmp(hashTable[(h-i*i)%P], s) == 0)
        {
            p = (h - i * i) % P;
            break;
        }
    }
    if (output++)
    {
        putchar(' ');
    }
    printf("%d", p);
    if (hashTable[p][0] == '\0')
        return p;
    else
        return -1;
}

void my_insert(char s[])
{
    int p = my_find(s);
    if (p != -1) strcpy(hashTable[p], s);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &P);
    for (unsigned i = 0; i < P; ++i)
    {
        hashTable[i][0] = '\0';
    }
    for (unsigned i = 0; i < N; ++i)
    {
        char s[9];
        scanf("%s", s);
        my_insert(s);
    }
    putchar('\n');
    return 0;
}

