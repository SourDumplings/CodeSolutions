#include <stdio.h>
#include <math.h>

float f(float A[], float x);

float f(float A[], float x)
{
    float result;
    result = A[3] * pow(x, 3) + A[2] * pow(x, 2) + A[1] * x + A[0];
    return result;
}

void solve(float A[], float a, float b);

float result;

void solve(float A[], float a, float b)
{
    float mid, *x0 = &result;
    if (f(A, a) == 0)
    {
        *x0 = a;
    }
    else if (f(A, b) == 0)
    {
        *x0 = b;
    }
    else
    {
        if (fabs(a - b) >= 0.001)
        {
            if (f(A, a) * f(A, b) < 0)
            {
                mid = (a + b) / 2;
                if (f(A, mid) == 0)
                {
                    *x0 = mid;
                }
                if (f(A, a) * f(A, mid) < 0)
                {
                    solve(A, a, mid);
                }
                else
                {
                    solve(A, mid, b);
                }
            }
        }
        else
        {
            *x0 = a;
        }
    }
}

int main()
{
    int i;
    float A[4];
    float a, b;

    scanf("%f %f %f %f", &A[3], &A[2], &A[1], &A[0]);

    scanf("%f %f", &a, &b);

    solve(A, a, b);

    printf("%.2f\n", result);

    return 0;
}

