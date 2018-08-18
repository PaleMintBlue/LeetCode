/*class Solution {
public:
    int superEggDrop(int K, int N) {
        std::vector<std::vector<int>> dp(N+1,std::vector<int>(K+1,0));
        int m = 0;
        while(dp[m][K]<N)
        {
            m++;
            for(int k = 1;k <= K;k++)
                dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1;
        }
        return m;
    }
};*/
/*
class Solution
{
public:
    int superEggDrop(int K, int N) {
        // dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1 
        // since we only use dp[m-1][k] once each time we can change the equation to 
        // dp[m-1][k] = dp[m-1][k-1] + dp[m-1][k] + 1 which is 
        // dp[m-1][k] += dp[m-1][k-1] + 1
        // since m-1 is of no use --> dp[k] += dp[k-1] + 1 
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++)
            for (int k = K; k > 0; --k)
                dp[k] += dp[k - 1] + 1;
        return m;
    }
};*/
/*
class Solution
{
public:
    int superEggDrop(int K, int N) {
        std::vector<std::vector<int>> dp(K+1,std::vector<int>(N+1));
        return helper(K,N,dp);
    }
private:
    int helper(int K,int N,std::vector<std::vector<int>>& dp)
    {
        if(N<=1)
            return N;
        if(K==1)
            return N;
        if(dp[K][N]>0)
            return dp[K][N];
        int min = N;
        for(int i = 1; i <= N;i++)
        {
            int left = helper(K-1,i-1,dp);
            int right = helper(K,N-i,dp);
            min = std::min(min,std::max(left,right)) + 1;
        }
        dp[K][N] = min;
        return min;
    }
};*/
class Solution
{
public:
    int superEggDrop(int K, int N) {
        std::vector<std::vector<int>> dp(K+1,std::vector<int>(N+1));
        return helper(K,N,dp);
    }
private:
    int helper(int K,int N,std::vector<std::vector<int>>& dp)
    {
        if(N<=1)
            return N;
        if(K==1)
            return N;
        if(dp[K][N]>0)
            return dp[K][N];
        int result = N;
        int low = 1, high = N;
        while(low < high)
        {
            int mid = low+(high-low)/2;
            int left = helper(K-1,mid-1,dp);
            int right = helper(K,N-mid,dp);
            result = std::min(result,std::max(left,right)) + 1;
            if(left==right)
                break;
            else if(left < right)
                low = mid+1;
            else
                high = mid;
        }
        dp[K][N] = result;
        return result;
    }
};