/*
 * @Author: SourDumplings
 * @Date: 2019-10-25 13:33:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/design-hashset/
 */

class MyHashSet
{
private:
    vector<list<int>> table;
    const int TABLE_SIZE = 1000;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        table.resize(TABLE_SIZE);
    }

    void add(int key)
    {
        table[key % TABLE_SIZE].push_back(key);
    }

    void remove(int key)
    {
        list<int> &l = table[key % TABLE_SIZE];
        l.remove(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        list<int> &l = table[key % TABLE_SIZE];
        return find(l.begin(), l.end(), key) != l.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */