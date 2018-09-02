/*
 @Date    : 2018-02-19 17:35:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1095
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>

using namespace std;

static const int MAXS = 86401;

struct Record
{
    string plate;
    int t;
    char status;
};

struct Car
{
    Car(string plate_, int in_, int out_): plate(plate_), in(in_), out(out_) {}
    string plate;
    int in, out;
};

int proess_time(const string &tempT)
{
    int h = stoi(tempT.substr(0, 2));
    int m = stoi(tempT.substr(3, 2));
    int s = stoi(tempT.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

bool cmp_record(const Record &r1, const Record &r2)
{
    if (r1.plate == r2.plate)
        return r1.t < r2.t;
    return r1.plate < r2.plate;
}

class cmp_out
{
public:
    bool operator() (Car* const &p1, Car* const &p2)
    { return p1->out > p2->out; }
};

bool cmp_parked_time(const Car &c1, const Car &c2)
{
    int d1 = c1.out - c1.in;
    int d2 = c2.out - c2.in;
    if (d1 == d2)
        return c1.plate < c2.plate;
    return d1 > d2;
}

string proess_time_back(int t)
{
    char res[10];
    int h = t / 3600;
    int s = t % 60;
    int m = (t - h * 3600 - s) / 60;
    sprintf(res, "%02d:%02d:%02d", h, m, s);
    return string(res);
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    vector<Record> record;
    string tempT, status;
    for (int i = 0; i != N; ++i)
    {
        Record r;
        cin >> r.plate >> tempT >> status;
        r.t = proess_time(tempT);
        r.status = status[0];
        record.push_back(std::move(r));
    }
    sort(record.begin(), record.end(), cmp_record);
    deque<Car> validRecord;
    for (int i = 0; i != N - 1; ++i)
    {
        if (record[i].status == 'i' && record[i+1].plate == record[i].plate &&
            record[i+1].status == 'o')
            validRecord.push_back(Car(record[i].plate, record[i].t, record[i+1].t));
    }
    sort(validRecord.begin(), validRecord.end(),
        [] (const Car &c1, const Car &c2)
        { return c1.in < c2.in; });
    deque<int> query;
    for (int i = 0; i != K; ++i)
    {
        cin >> tempT;
        query.push_back(proess_time(tempT));
    }

    priority_queue<Car*, vector<Car*>, cmp_out> parked;
    int nextCar = 0, validRecordNum = validRecord.size();
    int firstT = query[0] < validRecord[0].in ? query[0] : validRecord[0].in;
    for (int t = firstT; t != MAXS; ++t)
    {
        for (; nextCar != validRecordNum && t == validRecord[nextCar].in; ++nextCar)
            parked.push(&validRecord[nextCar]);
        for (; !parked.empty() && t == parked.top()->out; parked.pop());
        if (t == query.front())
        {
            printf("%d\n", parked.size());
            query.pop_front();
            if (query.empty())
                break;
        }
    }

    map<string, int> parkedTimeData;
    for (auto it = validRecord.begin(); it != validRecord.end(); ++it)
        parkedTimeData[it->plate] += it->out - it->in;
    int maxParkedTime = max_element(parkedTimeData.begin(), parkedTimeData.end(),
        [] (const pair<string, int> &p1, const pair<string, int> &p2)
        { return p1.second < p2.second; })->second;
    for (auto it = parkedTimeData.begin(); it != parkedTimeData.end();
        ++it)
        if (it->second == maxParkedTime)
            cout << it->first << ' ';
    cout << proess_time_back(maxParkedTime) << endl;
    return 0;
}
