class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int sum = 0, res = 0;
        int n = nums.size();
        cnt[0] = 1;
        for(int i = 0 ; i < n; i++){
            sum += nums[i];
            if(cnt.count(sum-k)){
                res += cnt[sum-k];
            }
            cnt[sum]++;
        }
        return res;
    }
};