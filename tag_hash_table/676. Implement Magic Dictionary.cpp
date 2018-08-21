// class MagicDictionary {
// public:
//     /** Initialize your data structure here. */
//     MagicDictionary() {
        
//     }
    
//     /** Build a dictionary through a list of words */
//     void buildDict(vector<string> dict) {
//         for(const auto& str:dict)
//         {
//             map[str.size()].push_back(str);
//         }
//     }
    
//     /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
//     bool search(string word) {
//         if(map.count(word.size())==0)
//             return false;
//         for(const auto& target:map[word.size()])
//         {
//             int cnt = 0,i;
//             for(i=0; i < word.size();i++)
//             {
//                 if(target[i]==word[i])
//                     continue;
//                 if(target[i]!=word[i]&&cnt==1)
//                     break;
//                 cnt++;
//             }
//             if(i==word.size()&&cnt==1)
//                 return true;
//         }
//         return false;
//     }
// private:
//     std::unordered_map<int,std::vector<std::string>> map;
// };

struct TrieNode
{
    bool isWord = false;
    TrieNode* children[26] = {nullptr};
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(const auto& str:dict)
        {
            TrieNode* temp = root;
            for(int i = 0; i < str.size(); i++)
            {
                if(temp->children[str[i]-'a']==nullptr)
                    temp->children[str[i]-'a'] = new TrieNode();
                temp = temp->children[str[i]-'a'];
            }
            temp->isWord = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size() ; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if((char)('a'+j)==word[i] || temp->children[j]==nullptr)
                    continue;
                if(helper(temp->children[j],word,i+1))
                    return true;
            }
            if(temp->children[word[i]-'a']==nullptr)
                return false;
            temp = temp->children[word[i]-'a'];
        }
        return false;
    }
    
    bool helper(TrieNode* root,std::string& word,int index)
    {
        for(int i = index;i < word.size();i++)
        {
            if(root->children[word[i]-'a']==nullptr)
                return false;
            root = root->children[word[i]-'a'];
        }
        return root->isWord;
    }
private:
    TrieNode* root = nullptr;
};


// /**
//  * Your MagicDictionary object will be instantiated and called as such:
//  * MagicDictionary obj = new MagicDictionary();
//  * obj.buildDict(dict);
//  * bool param_2 = obj.search(word);
//  */