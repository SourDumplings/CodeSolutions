/*
 * @Author: SourDumplings
 * @Date: 2020-12-28 11:00:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 */

class Trie
{
private:
    class TrieNode
    {
    public:
        char c;
        TrieNode *children[26];
        bool canBeLeaf;

        TrieNode() : canBeLeaf(false)
        {
            fill(children, children + 26, nullptr);
        }
    };


    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode)
    {}

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *cur = root;

        for (size_t i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (cur->children[c - 'a'] == nullptr)
            {
                cur->children[c - 'a'] = new TrieNode;
            }
            cur = cur->children[c - 'a'];
        }
        cur->canBeLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *cur = root;

        for (size_t i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (cur->children[c - 'a'])
            {
                cur = cur->children[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return cur->canBeLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;

        for (size_t i = 0; i < prefix.length(); i++)
        {
            char c = prefix[i];
            if (cur->children[c - 'a'])
            {
                cur = cur->children[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */