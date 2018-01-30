#include <stdio.h>
float f(float x);
float a3, a2, a1, a0;

int main()
{
	float a, b;
	scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
	scanf("%f %f", &a, &b);
	float left, mid, right;
	left = a;
	right = b;
	while (left <= right - 0.001 && f(left) * f(right) <= 0)
	{
		if (f(left) == 0)
		{
			printf("%.2f", left);
			return 0;
		}
		if (f(right) == 0)
		{
			printf("%.2f", right);
			return 0;
		}
		mid = (left + right) / 2;
		if (f(mid) * f(left) > 0)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	printf("%.2f", mid);
	return 0;
}

float f(float x)
{
	float result;
	result = a3*x*x*x + a2*x*x + a1*x + a0;
	return result;
}

