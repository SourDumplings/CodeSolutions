/*
 @Date    : 2017-12-05 20:44:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1036
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    int i, m = 0, f = 0;
    char sex;
    char id[11], name[11];
    int grade;
    char f_id[11], f_name[11];
    char m_id[11], m_name[11];
    int highest = 0, lowest = 100;
    for (i = 0; i < N; i++)
    {
        scanf("%s %c %s %d", name, &sex, id, &grade);
        if (sex == 'F')
        {
            f++;
            if (grade > highest)
            {
                strcpy(f_id, id);
                strcpy(f_name, name);
                highest = grade;
            }
        }
        else
        {
            m++;
            if (grade < lowest)
            {
                strcpy(m_id, id);
                strcpy(m_name, name);
                lowest = grade;
            }
        }
    }

    if (f)
    {
        printf("%s %s\n", f_name, f_id);
    }
    else
    {
        printf("Absent\n");
    }

    if (m)
    {
        printf("%s %s\n", m_name, m_id);
    }
    else
    {
        printf("Absent\n");
    }

    if (f && m)
    {
        printf("%d\n", highest-lowest);
    }
    else
    {
        printf("NA\n");
    }
    return 0;
}

