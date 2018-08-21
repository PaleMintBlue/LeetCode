class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
            return false;
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(dfs(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,int i,int j,string& word,
            int k)
    {
        if(k==(int)word.size())
            return true;
        if(i<0||j<0||i==(int)board.size()||j==(int)board[0].size())
            return false;
        char ch = board[i][j];
        if(word[k]!=ch)
            return false;
        board[i][j] = '#';
        if(dfs(board,i-1,j,word,k+1)||dfs(board,i+1,j,word,k+1)||
          dfs(board,i,j-1,word,k+1)||dfs(board,i,j+1,word,k+1))
            return true;
        board[i][j] = ch;
        return false;
    }
};