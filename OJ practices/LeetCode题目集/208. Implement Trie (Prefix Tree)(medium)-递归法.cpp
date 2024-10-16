/*
 * @Author: SourDumplings
 * @Date: 2020-12-25 22:00:56
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

    void do_insert(TrieNode *f, const string &word, int idx)
    {
        if (idx == word.length())
        {
            f->canBeLeaf = true;
            return;
        }

        char c = word[idx];
        TrieNode *&pChild = (f->children)[c - 'a'];
        if (!pChild)
        {
            pChild = new TrieNode;
            pChild->c = c;
        }
        do_insert(pChild, word, idx + 1);
    }

    bool do_search(TrieNode *f, const string &word, int idx)
    {
        if (idx == word.length())
        {
            return f->canBeLeaf;
        }

        char c = word[idx];
        TrieNode *&pChild = (f->children)[c - 'a'];
        if (!pChild)
        {
            return false;
        }
        return do_search(pChild, word, idx + 1);
    }

    bool do_startsWith(TrieNode *f, const string &word, int idx)
    {
        if (idx == word.length())
        {
            return true;
        }

        char c = word[idx];
        TrieNode *&pChild = (f->children)[c - 'a'];
        if (!pChild)
        {
            return false;
        }
        return do_startsWith(pChild, word, idx + 1);
    }

public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode)
    {}

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (word.empty())
        {
            return;
        }

        do_insert(root, word, 0);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (word.empty())
        {
            return false;
        }

        return do_search(root, word, 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.empty())
        {
            return false;
        }

        return do_startsWith(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */