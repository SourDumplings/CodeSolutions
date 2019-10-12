/*
 @Date    : 2018-01-11 11:18:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
 */

#ifndef COMPARE_H
#define COMPARE_H

template <typename T> int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}

#endif
