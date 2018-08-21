/*class Solution {
public:
    string longestWord(vector<string>& words) {
        std::sort(words.begin(),words.end());
        std::unordered_set<std::string> built;
        std::string res;
        for(const auto& word:words)
        {
            if(word.size()==1||built.count(word.substr(0,word.size()-1)))
            {
                res = word.size() > res.size() ? word : res;
                built.insert(word);
            }
        }
        return res;
    }
};*/
struct TrieNode
{
    bool isWord = false;
    TrieNode* children[26] = {nullptr};
};
class Solution {
public:
    Solution()
    {
        root = new TrieNode();
        root->isWord = true;
    }
    bool canForm(TrieNode* root,const std::string& word)
    {
        for(auto ch:word)
        {
            if(root->children[ch-'a']==nullptr||!root->isWord)
                return false;
            root = root->children[ch-'a'];
        }
        return root->isWord;
    }
    string longestWord(vector<string>& words) {
        for(const auto& str:words)
        {
            TrieNode* temp = root;
            for(auto ch:str)
            {
                if(temp->children[ch-'a']==nullptr)
                    temp->children[ch-'a'] = new TrieNode();
                temp = temp->children[ch-'a'];
            }
            temp->isWord = true;
        }
        std::string res;
        for(const auto& str:words)
        {
            if(str.size()>=res.size()&&canForm(root,str))
            {
                if(str.size()>res.size())
                    res = str;
                else
                {
                    if(str < res)
                        res = str;
                }
            }
        }
        return res;
    }
private:
    TrieNode* root = nullptr;
};