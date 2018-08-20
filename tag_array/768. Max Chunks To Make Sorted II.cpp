/*class Solution {
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
};*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        std::vector<int> sorted(arr.begin(),arr.end());
        std::sort(sorted.begin(),sorted.end());
        std::vector<int> duplicate_arr(arr.size(),0);
        for(int i = arr.size()-2; i>=0 ;i--)
        {
            if(sorted[i] == sorted[i+1])
                duplicate_arr[i] = duplicate_arr[i+1]+1;
        }
        int min = std::numeric_limits<int>::max();
        int counter = 0;
        int min_counter = 0;
        for(int i = arr.size()-1; i >= 0 ; i--)
        {
            if(arr[i]==min)
                min_counter++;
            else if(arr[i]<min)
            {
                min_counter = 0;
                min = arr[i];
            }
            if(min==sorted[i]&&min_counter==duplicate_arr[i])
                counter++;
        }
        return counter;
    }
};