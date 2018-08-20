class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        std::vector<int> sorted(arr.begin(),arr.end());
        std::sort(arr.begin(),arr.end());
        int sorted_count = 0;
        int count = 0;
        int ret = 0;
        for(int i = 0; i < arr.size() ; i++)
        {
            count += arr[i];
            sorted_count += sorted[i];
            if(count==sorted_count)
                ret++;
        }
        return ret;
    }
};