/*class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for (int i=k; ; i++) {

            // Push the current median.
            medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);

            // If all done, return.
            if (i == nums.size())
                return medians;

            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            // Erase nums[i-k].
            if (nums[i-k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
    }
};*/
class Solution {
public:
    // without use of priority_queue since priority_queue don't have erase method
    std::multiset<int,std::greater<int>> maxHeap;
    std::multiset<int> minHeap;
    
    void add(int num)
    {
        if(num < getMedian())
            maxHeap.insert(num);
        else
            minHeap.insert(num);
        if(maxHeap.size() > minHeap.size())
        {
            minHeap.insert(*maxHeap.begin());
            maxHeap.erase(maxHeap.begin());
        }
        if(minHeap.size() - maxHeap.size() > 1)
        {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }
    
    void remove(int num)
    {
        if (num < getMedian()) {
            maxHeap.erase(maxHeap.find(num));
        }
        else {
            minHeap.erase(minHeap.find(num));
        }
        if(maxHeap.size() > minHeap.size())
        {
            minHeap.insert(*maxHeap.begin());
            maxHeap.erase(maxHeap.begin());
        }
        if(minHeap.size() - maxHeap.size() > 1)
        {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }
    
    double getMedian() {
        if (maxHeap.empty() && minHeap.empty()) 
            return 0;
        if (maxHeap.size() == minHeap.size()) 
            return ((double)(*maxHeap.begin()) + (double)(*minHeap.begin())) / 2.0;
        else 
            return (double)(*minHeap.begin());
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        for(auto i = 0; i < nums.size();i++)
        {
            add(nums[i]);
            if(i>=k-1)
            {
                ret.push_back(getMedian());
                remove(nums[i-k+1]);
            }
        }
        return ret;
    }
};