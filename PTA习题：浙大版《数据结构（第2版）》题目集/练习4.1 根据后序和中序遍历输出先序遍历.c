/*
 @Date    : 2017-11-17 20:04:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6101
 */

#include <stdio.h>
#include <stdlib.h>

void PrintPreorder(int postorderl[], int poststart, int postend,
 int inorderl[], int instart, int inend)
{
    int root = postorderl[postend];
    if (postend <= poststart)
    {
        // 序列中只有一个或者0个元素
        if (postend == poststart)
        {
            // 序列中只有一个元素
            printf(" %d", root);
        }
        return;
    }
    printf(" %d", root);
    int i;
    for (i = instart; i < inend; i++)
    {
        // 找到根节点在中序遍历序列中的位置
        if (inorderl[i] == root)
        {
            break;
        }
    }
    int left_poststart, right_poststart, left_postend, right_postend;
    int left_instart, right_instart, left_inend, right_inend;
    left_poststart = poststart;
    right_postend = postend - 1;
    left_inend = i - 1;
    right_instart = i + 1;
    left_instart = instart;
    right_inend = inend;
    left_postend = left_poststart + left_inend - left_instart;
    right_poststart = right_postend - (right_inend - right_instart);
    PrintPreorder(postorderl, left_poststart, left_postend,
                inorderl, left_instart, left_inend);
    PrintPreorder(postorderl, right_poststart, right_postend,
                inorderl, right_instart, right_inend);
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int postorderl[N];
    int inorderl[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &postorderl[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &inorderl[i]);
    }
    printf("Preorder:");
    PrintPreorder(postorderl, 0, N-1, inorderl, 0, N-1);
    putchar('\n');
    return 0;
}

