/*
 @Date    : 2018-02-04 16:32:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/S/
 */

#include <cstdio>
#include <algorithm>

using namespace std;

class IntList
{
private:
    void my_clear()
    {
        ListNode *temp;
        for (ListNode *now = head->next; now;)
        {
            temp = now;
            now = now->next;
            delete temp;
        }
        tail = head;
        head->next = nullptr;
        return;
    }
public:
    struct ListNode
    {
        int num;
        ListNode *next = nullptr;
    };
    ListNode *head, *tail; // 记录单链表的头空结点和最后一个结点
    IntList() { head = new ListNode; tail = head; }
    ~IntList()
    {
        my_clear();
        delete head;
    }
    void my_push_back(int n)
    {
        ListNode *temp = new ListNode;
        temp->next = nullptr;
        temp->num = n;
        tail->next = temp;
        tail = temp;
        return;
    }
    ListNode* begin() { return head->next; }
    ListNode* end() { return tail; }
    void my_sort()
    {
        vector<int> tempv;
        for (ListNode *now = head->next; now; now = now->next)
            tempv.push_back(now->num);
        my_clear();
        sort(tempv.begin(), tempv.end());
        head = new ListNode;
        tail = head;
        for (vector<int>::iterator it = tempv.begin(); it != tempv.end(); ++it)
            my_push_back(*it);
        return;
    }
    void my_merge(IntList &l2)
    {
        for (ListNode *l2node = l2.head->next; l2node; l2node = l2node->next)
            my_push_back(l2node->num);
        l2.my_clear();
        return;
    }
    void my_unique()
    {
        ListNode *first = head->next;
        ListNode *last = first;
        ListNode *now = nullptr;
        while (true)
        {
            if (!first)
                break;
            for (last = first; last && last->num == first->num; last = last->next);
            ListNode *temp;
            for (now = first->next; now != last;)
            {
                temp = now;
                now = now->next;
                delete temp;
            }
            first->next = last;
            first = last;
        }
        return;
    }
    bool my_empty() { return tail == head; }
};

IntList *data[10000];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char order[100];
    while (n--)
    {
        scanf("%s", order);
        switch (order[0])
        {
            case 'n':
            {
                int id;
                scanf("%d", &id);
                data[id] = new IntList;
                break;
            }
            case 'a':
            {
                int id, num;
                scanf("%d %d", &id, &num);
                data[id]->my_push_back(num);
                break;
            }
            case 'o':
            {
                int id;
                scanf("%d", &id);
                data[id]->my_sort();
                int output = 0;
                for (IntList::ListNode *it = data[id]->begin(); it; it = it->next)
                {
                    if (output++)
                        putchar(' ');
                    printf("%d", it->num);
                    if (it == data[id]->end())
                        break;
                }
                putchar('\n');
                break;
            }
            case 'm':
            {
                int id1, id2;
                scanf("%d %d", &id1, &id2);
                data[id1]->my_merge(*data[id2]);
                break;
            }
            case 'u':
            {
                int id;
                scanf("%d", &id);
                data[id]->my_sort();
                data[id]->my_unique();
                break;
            }
        }
    }
    for (int i = 0; i != 10000; ++i)
    {
        if (data[i])
            delete data[i];
    }
    return 0;
}
