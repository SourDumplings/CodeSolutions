#include <stdio.h>

int main()
{
    int speed;

    scanf("%d", &speed);

    if (speed <= 60)
    {
        printf("Speed: %d - OK", speed);
    }
    else
    {
        printf("Speed: %d - Speeding", speed);
    }

    return 0;
}
