/*
 @Date    : 2017-11-19 16:04:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6259
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10000

typedef struct DATA *Data;
struct DATA
{
    int freq;
    char key[16];
};

int count_words = 0;

int Hash(char key[])
{
    // 按照单词的前两个元素进行划分，再乘以5，即前两位总共占据37*37*5 = 6845个位置
    // 顺序按照26个字母，数字，下划线,
    char first, second;
    first = key[0];
    second = key[1];
    int i;
    if (isalpha(first))
    {
        i = (first - 'a') * 37 * 5;
    }
    else if (isdigit(first))
    {
        i = (first - '0' + 'z' - 'a' + 1) * 37 * 5;
    }
    else
    {
        // 第一位是下划线
        i = 6660;
    }
    if (second)
    {
        if (isalpha(second))
        {
            i += (second - 'a') * 5;
        }
        else if (isdigit(second))
        {
            i += (second - '0' + 'z' - 'a' + 1) * 5;
        }
        else
        {
            i += 180;
        }
    }
    return i;
}

int LinearProbe(Data database[], int i, char key[])
{
    for (i += 1; database[i]->freq && strcmp(database[i]->key, key); i++);
    return i;
}

int InSert(Data database[], char key[])
{
    int i = Hash(key);
    if (database[i]->freq == 0)
    {
        strcpy(database[i]->key, key);
        database[i]->freq++;
        count_words++;
    }
    else if (strcmp(database[i]->key, key) == 0)
    {
        database[i]->freq++;
    }
    else
    {
        i = LinearProbe(database, i, key);
        if (!database[i]->freq)
        {
            count_words++;
        }
        strcpy(database[i]->key, key);
        database[i]->freq++;
    }
    return database[i]->freq;
}

int compare(const void *a, const void *b)
{
    int k;
    if ( ((*(Data *)a)->freq > ((*(Data *)b)->freq )))
    {
        k = -1;
    }
    else if ( ((*(Data *)a)->freq < ((*(Data *)b)->freq )))
    {
        k = 1;
    }
    else {
        if (strcmp(((*(Data *)a)->key), ((*(Data *)b)->key)) < 0)
            k = -1;
        else
            k = 1;
    }
    // printf("a->key:%s, b->key:%s\n", ((*(Data *)a)->key), ((*(Data *)b)->key));
    // printf("k = %d\n", k);
    return k;
}

int main()
{
    int i;
    Data database[MAX];
    for (i = 0; i < MAX; i++)
    {
        database[i] = (Data)malloc(sizeof(struct DATA));
        database[i]->freq = 0;
    }
    char line[MAX];
    // char word[81]; // 若单词超过80则分成两段
    char word[MAX]; // 若单词超过80则只取前80个元素
    int pw = 0;
    int end = 0;
    while (1)
    {
        gets(line);
        for (i = 0; line[i]; i++)
        {
            if (line[i] == '#')
            {
                end = 1;
                break;
            }
            // else if (pw < 80 && (isalnum(line[i]) || line[i] == '_')) // 若单词超过80则分成两段
            else if (isalnum(line[i]) || line[i] == '_') // 若单词超过80则只取前80个元素
            {
                line[i] = tolower(line[i]);
                word[pw++] = line[i];
            }
            else
            {
                if (!pw)
                {
                    continue;
                }
                else if (pw > 15)
                {
                    pw = 15;
                }
                word[pw] = '\0';
                int freq;
                freq = InSert(database, word);
                // printf("$$word is %s, its freq is %d$$\n", word, freq);
                // printf("$$now the number of words is %d$$\n", count_words);
                pw = 0;
            }
        }
        if (end)
        {
            break;
        }
    }
    printf("%d\n", count_words);

    // 排序过程
    // 将有效的节点提取出来
    Data result[count_words];
    int r_i = 0;
    for (i = 0; i < MAX; i++)
    {
        if (database[i]->freq)
        {
            result[r_i++] = database[i];
        }
        else
        {
            free(database[i]);
        }
    }

    // i = 0;
    // for (r_i = 0; r_i < count_words; r_i++)
    // {
    //     printf("%d: word:%s, freq:%d\n", i++, result[r_i]->key, result[r_i]->freq);
    // }

    qsort(result, count_words, sizeof(result[0]), compare);
    // i = 0;
    // for (r_i = 0; r_i < count_words; r_i++)
    // {
    //     printf("After sort, %d: word:%s, freq:%d\n", i++, result[r_i]->key, result[r_i]->freq);
    // }

    // 输出
    int show_num = (int)(count_words * 0.1);
    for (i = 0; i < show_num; i++)
    {
        printf("%d:%s\n", result[i]->freq, result[i]->key);
    }
    return 0;
}

