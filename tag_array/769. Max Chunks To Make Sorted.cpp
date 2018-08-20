/*class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        std::set<int> set;
        int count = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            set.insert(arr[i]);
            if(*set.rbegin() == i)
                count++;
        }
        return count;
    }
};*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int max = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            max = std::max(arr[i],max);
            if(max == i)
                count++;
        }
        return count;
    }
};