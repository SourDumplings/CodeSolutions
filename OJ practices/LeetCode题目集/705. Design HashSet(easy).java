import java.util.ArrayList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-25 13:44:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/design-hashset/
 */

class MyHashSet
{
    private final int TABLE_SIZE = 1000;
    private final List<List<Integer>> table;

    /** Initialize your data structure here. */
    public MyHashSet()
    {
        table = new ArrayList<>(TABLE_SIZE);
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table.add(new LinkedList<Integer>());
        }
    }

    public void add(int key)
    {
        table.get(key % TABLE_SIZE).add(key);
    }

    public void remove(int key)
    {
        table.get(key % TABLE_SIZE).removeIf(k -> k == key);
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key)
    {
        return table.get(key % TABLE_SIZE).contains(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */