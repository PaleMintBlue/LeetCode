class Solution {
public:
    int numTrees(int n) {
        if(n<0)
            return 0;
        vector<int> G(n+1);
        G[0] = G[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 1;j<=i;j++)
            {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
    /*int countTrees(int start,int end)
    {
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        int count = 0;
        for(int i = start;i<=end;i++)
        {
            int left = countTrees(start,i-1);
            int right = countTrees(i+1,end);
            if(left==0)
                count += right;
            else if(right==0)
                count += left;
            else
                count += left*right;
        }
        return count;
    }*/
};