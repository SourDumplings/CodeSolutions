#include <stdio.h>

int main()
{
    char ch;
    int a, b, result;
    int first = 1;
    int flag = 1;
    do
    {
        if (first)
        {
            scanf("%d", &a);
            result = a;
            first = 0;
        }
        scanf("%c", &ch);
        if (ch != '=')
        {
            scanf("%d", &b);
            switch(ch)
            {
                case '+' : result = result + b; break;
                case '-' : result = result - b; break;
                case '*' : result = result * b; break;
                case '/':
                {
                    if (!b)
                    {
                        flag = 0;
                    }
                    else
                    {
                        result = result / b;
                    }
                    break;
                }
                default : flag = 0; break;
            }
        }
        else
        {
            printf("%d\n",result);
            break;
        }
    } while (flag);

    if (!flag)
    {
        printf("ERROR\n");
    }
    return 0;
}
