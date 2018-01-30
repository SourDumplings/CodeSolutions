#include<stdio.h>

int main ()
{
    char s1[81], s2[81];
    gets(s1);
    gets(s2);

    int i = 0, j = 0, count = 0;
    while (s1[i] != NULL) {
        // 读取完了全部的str2，开始将str1中出现str2的部分删除
        if (s2[count] == NULL && count > 0) {
            // j为str1中待替换的位置，即初始化为出现str2的第一个位置
            j = i - count;
            // 将出现str2的str1部分的后面部分拼接到str1中出现str2的前面部分的后面
            while (s1[i] != NULL) {
                s1[j++] = s1[i++];
            }
            s1[j] = NULL;
            i = 0;
            count = 0;
            continue;
        }
        if (s1[i] == s2[count]) {
            // count代表的是str2的长度
            count ++;
        } else if (s1[i] == s2[0]) {
            count = 1; // 每一次不再匹配后，都要再和子串的第一个字符比较，以免漏过如s1为ccat (s2为 cat)的情况
        } else {
            count = 0;
        }
        i++;
    }
    if (s2[count] == NULL && count > 0) {
        s1[i-count] = NULL;
    } //处理要删除的字串在 s1 末尾的情况
    puts(s1); //puts 函数遇 NULL 才会结束
    return 0;
}
