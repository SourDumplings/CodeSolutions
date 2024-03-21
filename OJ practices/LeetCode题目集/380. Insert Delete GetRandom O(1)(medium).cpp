/**
 * @file 380. Insert Delete GetRandom O(1)(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 写一个类实现增删查
 * @version 1.0.0
 * @date 2024-03-21
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 使用哈希表和动态数组即可，删元素那里要细细品
 * https://leetcode.cn/problems/insert-delete-getrandom-o1/solutions/1411578/o1-shi-jian-cha-ru-shan-chu-he-huo-qu-su-rlz2/?envType=study-plan-v2&envId=top-interview-150
 */

class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(nullptr));
    }

    bool insert(int val)
    {
        if (m_num2IdxMap.find(val) != m_num2IdxMap.end())
        {
            return false;
        }

        m_nums.emplace_back(val);
        m_num2IdxMap[val] = m_nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m_num2IdxMap.find(val) == m_num2IdxMap.end())
        {
            return false;
        }

        // 与最后一个元素交换后再 pop
        // 这样使得 vector 能够较快地移除元素
        // 并且这样可以保证哈希一致性
        // 注意删除元素要放在最后！
        int idx = m_num2IdxMap.at(val);
        m_num2IdxMap[m_nums.back()] = idx;
        m_nums[idx] = m_nums.back();
        m_num2IdxMap.erase(val);
        m_nums.pop_back();
        return true;
    }

    int getRandom()
    {
        return m_nums[rand() % m_nums.size()];
    }

private:
    vector<int> m_nums;
    unordered_map<int, int> m_num2IdxMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
