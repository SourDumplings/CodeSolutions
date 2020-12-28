/*
 * @Author: SourDumplings
 * @Date: 2020-12-28 09:10:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/
 */

class WordDictionary
{
private:
    class TrieNode
    {
    public:
        bool canBeLeaf;
        char c;
        TrieNode *children[26];

        TrieNode() : canBeLeaf(false)
        {
            fill(children, children + 26, nullptr);
        }
    };

    TrieNode *root;

    bool searchHelp(TrieNode *f, const string &word)
    {
        TrieNode *cur = f;
        for (int i = 0; i < word.length(); i++)
        {
            // 对于 . , 递归的判断所有不为空的孩子
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (cur->children[j])
                    {
                        if (searchHelp(cur->children[j], word.substr(i + 1)))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            // 不含有当前节点
            if (cur->children[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            cur = cur->children[word[i] - 'a'];
        }
        // 当前节点是否为是某个单词的结束
        return cur->canBeLeaf;

    }


public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode)
    {

    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            // 当前孩子是否存在
            if ((cur->children)[c - 'a'] == nullptr)
            {
                (cur->children)[c - 'a'] = new TrieNode;
            }
            cur = cur->children[c - 'a'];
        }
        // 当前节点代表结束
        cur->canBeLeaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchHelp(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */