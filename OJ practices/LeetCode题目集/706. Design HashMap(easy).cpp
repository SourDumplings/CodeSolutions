/*
 * @Author: SourDumplings
 * @Date: 2019-10-26 15:43:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/design-hashmap/
 */

class MyHashMap
{
private:
    const int TABLE_SIZE = 1000;
    vector<list<pair<int, int>>> table;

    pair<int, int> *find(int key)
    {
        list<pair<int, int>> &l = table[key % TABLE_SIZE];
        for (auto &&p : l)
        {
            if (p.first == key)
            {
                return &p;
            }
        }
        return nullptr;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        table.resize(TABLE_SIZE);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        pair<int, int> *p = find(key);
        if (p)
        {
            p->second = value;
        }
        else
        {
            table[key % TABLE_SIZE].push_back(make_pair(key, value));
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        pair<int, int> *p = find(key);
        if (p)
        {
            return p->second;
        }
        else
        {
            return -1;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        list<pair<int, int>> &l = table[key % TABLE_SIZE];
        for (auto it = l.begin(); it != l.end(); it++)
        {
            if (it->first == key)
            {
                l.erase(it);
                break;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */