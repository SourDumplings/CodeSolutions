#include <stdio.h>
#include <stdlib.h>

#define MAXK 5
#define ERROR -1
#define MAXN 10000

typedef struct USER *User;
struct USER
{
    int s[MAXK];
    int total_score;
    int valid_submission; // 记录该用户是否进行了有效的提交
    int perfect_solve; // 记录用户完美解决的问题数
};

User u[MAXN];
int rank_list[MAXN]; // 存的是各个排名的id

int compare(const void *a, const void *b)
{
    int k = 1;
    int *c = (int *)a;
    int *d = (int *)b;
    if (u[*c]->total_score > u[*d]->total_score)
    {
        k = -1;
    }
    else if (u[*c]->total_score == u[*d]->total_score)
    {
        if (u[*c]->perfect_solve > u[*d]->perfect_solve)
        {
            k = -1;
        }
        else if (u[*c]->perfect_solve == u[*d]->perfect_solve && *c < *d)
        {
            k = -1;
        }
    }
    return k;
}

void Table_Sort(int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        rank_list[i] = i;
    }
    qsort(rank_list, N, sizeof(int), compare);
    return;
}

void OutPut(int N, int K)
{
    int i;
    int rank;
    int count = 0;
    int j;
    for (i = 0; i < N; i++)
    {
        if (u[rank_list[i]]->total_score == -1)
        {
            break;
        }
        if (!count || u[rank_list[i]]->total_score < u[rank_list[i-1]]->total_score)
        {
            rank = count + 1;
        }
        printf("%d %05d %d ", rank, rank_list[i]+1, u[rank_list[i]]->total_score);
        count++;
        for (j = 0; j < K; j++)
        {
            if (u[rank_list[i]]->s[j] == -2)
            {
                printf("-");
            }
            else if (u[rank_list[i]]->s[j] == -1)
            {
                printf("0");
            }
            else
            {
                printf("%d", u[rank_list[i]]->s[j]);
            }
            if (j < K - 1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
    return;
}

int main()
{
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    int p[K];
    int i;
    // 读入各道题的总分数
    for (i = 0; i < K; i++)
    {
        scanf("%d", &p[i]);
    }
    // 初始化每个用户
    int id;
    int problem_id, score;
    int j;
    for (i = 0; i < N; i++)
    {
        u[i] = (User)malloc(sizeof(struct USER));
        u[i]->total_score = 0;
        u[i]->valid_submission = 0;
        u[i]->perfect_solve = 0;
        for (j = 0; j < K; j++)
        {
            u[i]->s[j] = -2; // -2表示还未有过提交
        }
    }
    // 读入每次的提交结果
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &id, &problem_id, &score);
        id--;
        problem_id--;
        if (score > u[id]->s[problem_id])
        {
            if (!(u[id]->valid_submission) && score != -1)
            {
                u[id]->valid_submission = 1;
            }
            if (u[id]->s[problem_id] >= 0)
            {
                u[id]->total_score -= u[id]->s[problem_id];
            }
            if (score == p[problem_id] && u[id]->s[problem_id] != p[problem_id])
            {
                u[id]->perfect_solve += 1;
            }
            u[id]->s[problem_id] = score;
            if (score > 0)
            {
                u[id]->total_score += score;
            }
        }
    }
    // 将没有有效提交的用户的总成绩置为-1
    for (i = 0; i < N; i++)
    {
        if (!(u[i]->valid_submission))
        {
            u[i]->total_score = -1;
        }
    }
    // 按照总分给出排名
    Table_Sort(N);
    // 输出每个用户的成绩
    OutPut(N, K);
    return 0;
}

