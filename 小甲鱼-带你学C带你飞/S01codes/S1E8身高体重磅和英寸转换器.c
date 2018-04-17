#include <stdio.h>

int main()
{
    char name[256];
    float h, w;

    printf("请输入您的姓名：");
    scanf("%s", &name);

    printf("请输入您的身高（cm）：");
    scanf("%f", &h);

    printf("请输入您的体重（kg）：");
    scanf("%f", &w);

    printf("========= 正在为您转换 =========\n");

    h = h * 0.3937008;
    w = w * 2.2046226;

    printf("%s的身高是%.2f（in），体重是%f（lb）。\n", name, h, w);

    return 0;
}
