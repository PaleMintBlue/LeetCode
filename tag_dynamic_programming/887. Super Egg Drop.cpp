class Solution {
public:
    /*int superEggDrop(int K, int N) {
        std::vector<std::vector<int>> dp(N+1,std::vector<int>(K+1,0));
        int m = 0;
        while(dp[m][K]<N)
        {
            m++;
            for(int k = 1;k <= K;k++)
                dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1;
        }
        return m;
    }*/
    int superEggDrop(int K, int N) {
        /*
        * dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1 
        * since we only use dp[m-1][k] once each time we can change the equation to 
        * dp[m-1][k] = dp[m-1][k-1] + dp[m-1][k] + 1 which is 
        * dp[m-1][k] += dp[m-1][k-1] + 1
        * since m-1 is of no use --> dp[k] += dp[k-1] + 1 
        */
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++)
            for (int k = K; k > 0; --k)
                dp[k] += dp[k - 1] + 1;
        return m;
    }
};