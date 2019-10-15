#include <stdio.h>

int main()
{
        float fah, cel;

        printf("请输入摄氏度：");
        scanf("%f", &cel);

        fah = 9.0 / 5.0 * cel + 32;
        printf("转换为华摄度是：%.2f\n", fah);

        return 0;
}
