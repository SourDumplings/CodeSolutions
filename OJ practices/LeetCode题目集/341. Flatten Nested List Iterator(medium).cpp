/*
 * @Author: SourDumplings
 * @Date: 2021-04-13 10:54:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/flatten-nested-list-iterator/
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
private:
    vector<int> thisIntegers;
    vector<NestedInteger> *pNestedList;
    int thisIndex1, thisIndex2;
    int n;

    void fill_this_integers(const NestedInteger *pNestedInteger)
    {
        if (pNestedInteger->isInteger())
        {
            thisIntegers.push_back(pNestedInteger->getInteger());
        }
        else
        {
            const vector<NestedInteger> &list = pNestedInteger->getList();
            for (const NestedInteger &nestedInteger : list)
            {
                fill_this_integers(&nestedInteger);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList)
        : pNestedList(&nestedList), thisIndex1(-1), thisIndex2(-1),
          n(nestedList.size())
    {

    }

    int next()
    {
        return thisIntegers[++thisIndex2];
    }

    bool hasNext()
    {
        if (thisIndex1 >= n - 1 && thisIndex2 >= thisIntegers.size() - 1)
        {
            return false;
        }
        else if (thisIndex2 < thisIntegers.size() - 1)
        {
            return true;
        }
        else
        {
            NestedInteger *pNestedInteger = &((*pNestedList)[++thisIndex1]);
            thisIndex2 = -1;
            thisIntegers.clear();

            while (thisIntegers.empty() && thisIndex1 < n)
            {
                fill_this_integers(pNestedInteger);
                pNestedInteger = &((*pNestedList)[++thisIndex1]);
            }
            --thisIndex1;
            return !thisIntegers.empty();
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */