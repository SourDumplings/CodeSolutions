#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char str[4][61];
    int l[4];
    int i;
    int flag = 0;

    for (i = 0; i < 4; i++)
    {
        gets(str[i]);
    }

    for (i = 0; i < 4; i++)
    {
        l[i] = strlen(str[i]);
    }

    for (i = 0; i < l[0]; i++)
    {
        if (str[0][i] == str[1][i])
        {
            if (!flag && (str[0][i] >= 65) && (str[0][i] <= 71))
            {
                printf("%s ", day[str[1][i]-65]);
                flag = 1;
            }
            else if (flag == 1 && (str[0][i] >= 48) && (str[0][i] <= 57))
            {
                printf("%02d:", str[1][i]-48);
                break;
            }
            else if (flag == 1 && (str[0][i] >= 65) && (str[0][i] <= 78))
            {
                printf("%02d:", str[1][i]-55);
                break;
            }
        }
    }

    for (i = 0; i < l[2]; i++)
    {
        if (str[3][i] == str[2][i] && isalpha(str[2][i]))
        {
            printf("%02d\n", i);
            return 0;
        }
    }
}
