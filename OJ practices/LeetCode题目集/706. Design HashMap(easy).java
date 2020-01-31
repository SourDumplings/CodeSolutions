import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-26 15:54:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/design-hashmap/
 */

class MyHashMap
{

    class Pair<K, V>
    {
        private K key;
        private V value;

        Pair(K key, V value)
        {
            this.key = key;
            this.value = value;
        }

        K getKey()
        {
            return key;
        }

        V getValue()
        {
            return value;
        }

        void setKey(K key)
        {
            this.key = key;
        }

        void setValue(V value)
        {
            this.value = value;
        }
    }

    private final int TABLE_SIZE;
    private List<List<Pair<Integer, Integer>>> table;

    private Pair<Integer, Integer> find(int key)
    {
        List<Pair<Integer, Integer>> list = table.get(key % TABLE_SIZE);
        for (Pair<Integer, Integer> p : list)
        {
            if (p.getKey().intValue() == key)
            {
                return p;
            }
        }
        return null;
    }

    /** Initialize your data structure here. */
    public MyHashMap()
    {
        TABLE_SIZE = 1000;
        table = new ArrayList<>(TABLE_SIZE);
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table.add(new LinkedList<>());
        }
    }

    /** value will always be non-negative. */
    public void put(int key, int value)
    {
        Pair<Integer, Integer> pair = find(key);
        if (pair == null)
        {
            table.get(key % TABLE_SIZE).add(new Pair<>(key, value));
        }
        else
        {
            pair.setValue(value);
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key)
    {
        Pair<Integer, Integer> pair = find(key);
        if (pair == null)
        {
            return -1;
        }
        else
        {
            return pair.getValue();
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key)
    {
        List<Pair<Integer, Integer>> list = table.get(key % TABLE_SIZE);
        list.removeIf(p -> p.getKey() == key);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */