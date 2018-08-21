struct TrieNode
{
public:
    string word;
    TrieNode* next[26] = {nullptr};
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(const auto& str:words)
            insertWord(str,root);
        vector<string> ret;
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[i].size();j++)
            {
                dfs(board,i,j,root,ret);
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& board,int i,int j,TrieNode* root,
            vector<string>& ret)
    {
        char ch = board[i][j];
        if(ch=='#'||root->next[ch-'a']==nullptr)
            return;
        root = root->next[ch-'a'];
        if(!root->word.empty())
        {
            ret.push_back(root->word);
            root->word.clear();
        }
        board[i][j] = '#';
        if(i>0)
            dfs(board,i-1,j,root,ret);
        if(i<board.size()-1)
            dfs(board,i+1,j,root,ret);
        if(j>0)
            dfs(board,i,j-1,root,ret);
        if(j<board[0].size()-1)
            dfs(board,i,j+1,root,ret);
        board[i][j] = ch;
    }
    
    Solution()
    {
        root = new TrieNode();
    }
    
    void insertWord(string word,TrieNode* root)
    {
        TrieNode* p = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!p->next[word[i]-'a'])
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->word = word;
    }
private:
    TrieNode* root = nullptr;

};