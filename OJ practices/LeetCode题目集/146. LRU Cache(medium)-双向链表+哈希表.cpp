/**
 * @file 146. LRU Cache(medium)-双向链表+哈希表.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 模拟 LRU 主要是实现双向链表
 * @version 1.0.0
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

struct DLNode
{
    DLNode *prev;
    DLNode *next;
    int key;
    int val;
};

class LRUCache
{
public:
    LRUCache(int capacity)
        : m_capacity(capacity)
    {
        m_pHead = new DLNode;
        m_pTail = new DLNode;
        m_pHead->next = m_pTail;
        m_pHead->prev = m_pTail;
        m_pTail->next = m_pHead;
        m_pTail->prev = m_pHead;
    }

    ~LRUCache()
    {
        DLNode *pNode = m_pHead;
        while (pNode->next != m_pTail)
        {
            DLNode *pNext = pNode->next;
            delete pNode;
            pNode = pNext;
        }
        delete m_pTail;
    }

    int get(int key)
    {
        auto it = m_posMap.find(key);
        if (it == m_posMap.end())
        {
            return -1;
        }

        DLNode *pNode = it->second;
        moveToFront(pNode);
        return pNode->val;
    }

    void put(int key, int value)
    {
        auto it = m_posMap.find(key);
        if (it == m_posMap.end())
        {
            DLNode *pNode = nullptr;
            if (m_posMap.size() == m_capacity)
            {
                pNode = removeBack();
                m_posMap.erase(pNode->key);
                moveToFront(pNode);
            }
            else
            {
                pNode = new DLNode;
                insertToFront(pNode);
            }
            pNode->key = key;
            pNode->val = value;
            m_posMap[key] = pNode;
        }
        else
        {
            DLNode *pNode = it->second;
            moveToFront(pNode);
            pNode->val = value;
        }
    }

private:
    DLNode *m_pHead;
    DLNode *m_pTail;
    int m_capacity;
    unordered_map<int, DLNode *> m_posMap;

    DLNode *removeNode(DLNode *pNode)
    {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
        return pNode;
    }

    DLNode *removeBack()
    {
        return removeNode(m_pTail->prev);
    }

    void moveToFront(DLNode *pNode)
    {
        pNode = removeNode(pNode);
        insertToFront(pNode);
    }

    void insertToFront(DLNode *pNode)
    {
        m_pHead->next->prev = pNode;
        pNode->next = m_pHead->next;
        pNode->prev = m_pHead;
        m_pHead->next = pNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
