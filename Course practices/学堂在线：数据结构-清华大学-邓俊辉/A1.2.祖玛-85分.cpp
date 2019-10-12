/*
 @Date    : 2018-02-05 12:15:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1143
 */

#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode
{
    char letter;
    ListNode *next;
};

struct List
{
    ListNode *head, *last;
    List() { head = new ListNode; head->next = nullptr; head->letter = 'h'; last = head; }
    void my_push_back(char c)
    {
        ListNode *temp = new ListNode;
        temp->letter = c;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
        return;
    }
    void my_insert(int pos, char c)
    {
        ListNode *before = head;
        int count = -1;
        for (before = head; before->next && count != pos - 1; before = before->next, ++count);
        ListNode *temp = new ListNode;
        temp->next = before->next;
        temp->letter = c;
        before->next = temp;
        if (before == head)
            last = temp;
        eliminate();
        return;
    }
    ~List()
    {
        for (ListNode *now = head->next; now;)
        {
            ListNode *temp = now;
            now = now->next;
            delete temp;
        }
    }
    void output()
    {
        if (last == head)
            putchar('-');
        else
        {
            for (ListNode *now = head->next; now; now = now->next)
                printf("%c", now->letter);
        }
        putchar('\n');
        return;
    }
private:
    void eliminate()
    {
        ListNode *end = nullptr;
        ListNode *first = nullptr;
        ListNode *before = nullptr;
        // before 记录first的前一个结点，first记录第一个，
        // end记录最后一个与first颜色相同的结点的后一个结点
        ListNode *lastSame = nullptr;
        // lastSame记录最后一个与first颜色相同的结点
        while (last != head)
        {
            bool elimination = false;
            for (before = head; before->next;)
            {
                first = before->next;
                if (!first->next)
                {
                    last = first;
                    break;
                }
                int count = 1;
                lastSame = first;
                for (end = first->next; end && end->letter == first->letter; end = end->next)
                {
                    lastSame = end;
                    ++count;
                }
                if (count >= 3)
                {
                    elimination = true;
                    for (ListNode *now = first; now != end;)
                    {
                        ListNode *temp = now;
                        now = now->next;
                        delete temp;
                    }
                    before->next = end;
                    if (!end)
                        last = head;
                }
                else
                    before = lastSame;
            }
            if (!elimination)
                break;
        }
    }
};

int main(int argc, char const *argv[])
{
    List L;
    int n;
    char seq[10001];
    gets(seq);
    for (int i = 0; seq[i]; ++i)
        L.my_push_back(seq[i]);
    scanf("%d", &n);
    while (n--)
    {
        int pos;
        char letter;
        scanf("%d %c", &pos, &letter);
        L.my_insert(pos, letter);
        // printf("head = %c, last = %c\n", L.head->letter, L.last->letter);
        L.output();
    }

    return 0;
}
