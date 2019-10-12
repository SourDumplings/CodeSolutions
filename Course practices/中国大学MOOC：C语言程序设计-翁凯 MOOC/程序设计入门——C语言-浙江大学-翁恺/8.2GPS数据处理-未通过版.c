#include <stdio.h>
#include <string.h>

#define MAX 99999

void UTC2Beijing(int utc[])
{
    int hour, min, sec;
    hour = (utc[0] * 10 + utc[1] + 8) % 24;
    min = utc[2] * 10 + utc[3];
    sec = utc[4] * 10 + utc[5];
    printf("%02d:%02d:%02d\n", hour, min, sec);
    return;
}

int main()
{
    int utc[6];
    char gps[MAX];
    char temp[MAX];
    while(1)
    {
        gets(temp);
        if (!strcmp(temp, "END"))
        {
            break;
        }
        strcpy(gps, temp);
        // 判断是否是$GPRMC语句
        if (strncmp(gps, "$GPRMC,", 7))
        {
            continue;
        }
        int i;
        char check = gps[1];
        int code = 0;
        int content = 1;
        // 根据校验码判断语句是否正确
        for (i = 2; i < strlen(gps); i++)
        {
            if (gps[i] == '*')
            {
                content = 0;
                continue;
            }
            if (content == 1)
            {
                // 意味着还在内容段
                check = check ^ gps[i];
            }
            else if (!content)
            {
                // 读到了校验码的第一位
                code = (gps[i] - '0') * 16;
                content = 2;
            }
            else if (content == 2)
            {
                // 读到了校验码的第二位
                code += gps[i] - '0';
            }
        }
        if (check == code && gps[18] == 'A')
        // 说明校验通过并且已定位, 得到UTC时间
        {
            int j = 0;
            for (i = 7; i <= 12; i++)
            {
                utc[j++] = gps[i] - '0';
            }
        }
    }
    UTC2Beijing(utc);

    return 0;
}
