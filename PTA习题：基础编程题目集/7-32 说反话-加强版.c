#include <stdio.h>
#include <string.h>

#define MAX 500001

int main()
{
    char str[MAX];
    char sentence[MAX];
    int flag = 0;
    int i, j = 0;
    int l_s;
    int l_w = 0; //统计单词的长度

    gets(str);

    // 先去掉多余空格形成新字符串
    for (i = 0; i <= MAX - 1; i++)
    {
        if (str[i] != ' ')
        {
            flag = 1;
            sentence[j++] = str[i];
        }
        else
        {
            if (flag)
            {
                sentence[j++] = str[i];
            }
            flag = 0;
        }
    }

    // puts(sentence);
    l_s = strlen(sentence);
    flag = 0;

    // 倒序输出sentence
    for (i = l_s - 1; i >= 0; i--)
    {
        if (sentence[i] != ' ')
        {
            l_w++;
        }
        else
        {
            // 碰到空格就输出单词
            for (j = i; j < l_w + i; j++)
            {
                printf("%c", sentence[j+1]);
                flag = 1; // 代表输出过了单词，可以输出空格了
            }
            l_w = 0;
            if (i && flag)
            {
                putchar(' ');
            }
        }
    }

    // 还剩第一个单词没有输出
    for (j = 0; j < l_w; j++)
        {
            printf("%c", sentence[j]);
        }
    putchar('\n');



    return 0;
}
