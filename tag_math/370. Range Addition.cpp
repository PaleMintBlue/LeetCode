class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here
        /*
        Given:
            length = 5,
            updates = 
            [
            [1,  3,  2],
            [2,  4,  3],
            [0,  2, -2]
            ]
            return [-2, 0, 3, 5, 3]
            [0+0+(-2) 2+0+(-2) 2+3+(-2) 2+3+0 0+3+0] 
            so we can set the num at begin and -num at end
            and sum at the end
            setting that can help us do the operation at first 
            and eliminate the operation when it meet the negative num
        */
        vector<int> ret(length+1,0);
        for(const auto& update:updates)
        {
            ret[update[0]] += update[2];
            ret[update[1]+1] -= update[2];
        }
        
        for(int i = 1; i < ret.size();i++)
        {
            ret[i] += ret[i-1];   
        }
        
        ret.resize(length);
        
        return ret;
    }
};