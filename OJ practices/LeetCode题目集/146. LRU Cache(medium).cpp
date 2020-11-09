/*
 * @Author: SourDumplings
 * @Date: 2020-11-08 10:51:31
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/lru-cache/
 */

class LRUCache
{
public:
    LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        else
        {
            for (auto it = visited.begin(); it != visited.end(); ++it)
            {
                if (*it == key)
                {
                    visited.erase(it);
                    visited.push_back(key);
                    break;
                }
            }
            return m[key];
        }
    }

    void put(int key, int value)
    {
        if (m.find(key) == m.end())
        {
            if (m.size() == capacity)
            {
                int tempK = visited.front();
                m.erase(tempK);
                visited.pop_front();
            }
        }
        else
        {
            for (auto it = visited.begin(); it != visited.end(); ++it)
            {
                if (*it == key)
                {
                    visited.erase(it);
                    break;
                }
            }
        }
        visited.push_back(key);
        m[key] = value;
    }
private:
    int capacity;
    unordered_map<int, int> m;
    list<int> visited;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */