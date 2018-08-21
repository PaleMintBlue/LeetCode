struct TrieNode
{
public:
    TrieNode* next[26] = {nullptr};
    bool isWord = false;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0;i<word.size();i++)
        {
           if(!p->next[word[i]-'a'])
                    p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word,0,root);
    }
private:
    TrieNode* root;
    bool find(string& word,int start,TrieNode* node)
    {
        TrieNode* p = node;
        for(int i = start;i<word.size()&&p;i++)
        {
            if(word[i]!='.')
                p = p->next[word[i]-'a'];
            else
            {
                TrieNode* tmp = p;
                for(int j = 0;j<26;j++)
                {
                    p = tmp->next[j];
                    if(find(word,i+1,p))
                        return true; 
                }
            }
        }
        return p&&p->isWord;
    }
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */