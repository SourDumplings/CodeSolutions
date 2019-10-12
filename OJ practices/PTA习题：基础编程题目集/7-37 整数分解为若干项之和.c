#include <stdio.h>

int N;

int s[31] = {0}; // 存放划分结果
int top = -1; // 数组指针
int count = 0; // 统计输出的次数
int sum = 0; // 拆分项累加和
int flag = 0; // 记录分解的算式的累加结果是否已经超过了N

void division(int i)
{
    // 输出并跳出
    if (sum == N)
    {
        count++;
        printf("%d=", N);

        int k;
        for (k = 0; k < top; k++)
        {
            printf("%d+", s[k]);
        }

        // 输出最后一个数字并判断是否在一行中输出了4个式子，输出分号或换行
        if (count % 4 == 0 || s[top] == N)
        {
            printf("%d\n", s[top]);
        }
        else
        {
            printf("%d;", s[top]);
        }
        return;
    }

    // 加多了，跳出
    if (sum > N)
    {
        flag = 1;
        return;
    }

    // 对分解结果的每一位按从后到前进行扫描累加
    // 相当于把每一个小于等于N的整数从后往前加到每一位都试一遍
    // 每一层递归都是对每一位的处理
    // 如果sum刚好加出了N的值则输出，如果比N小则这一位换下一个数（j+1）试试
    // 如果sum比N大了则直接跳出，再扫描前一位
    // 前一位直接就从后一位使得sum大于N的数开始，比如N=3,1+1+2>3，则就从1+2开始，而不是从1+1再开始
    int j;
    for (j = i; j <= N; j++)
    {
        s[++top] = j;
        sum += j;
        division(j);
        top--;
        sum -= j;
        if (flag)
        {
            flag = 0;
            return;
        }
    }
}

int main()
{

    scanf("%d", &N);

    division(1);

    return 0;
}
