/*
 @Date    : 2017-11-13 09:12:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
在此处添加文件说明
 */

#include <stdio.h>
#define TOL 1E-2

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

/* 你的代码将被嵌在这里 */
double dist(double h, double p)
{
    double d = h;
    h *= p;
    while (h >= TOL)
    {
        d += 2 * h;
        h *= p;
    }
    return d;
}
