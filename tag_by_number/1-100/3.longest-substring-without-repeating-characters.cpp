// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     	std::unordered_set<int> set;
//     	int i = 0, j = 0;
//     	int max = 0;
//     	while(j < s.size())
//     	{
//     		if(set.find(s[j]) == set.end())
//     		{
//     			set.insert(s[j++]);
//     			max = std::max(max,static_cast<int>(set.size()));
//     		}else
//     		{
//     			set.erase(s[i++]);
//     		}
//     	}
//     	return max;
//     }
// };




class Solution {
public:
/**
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 */
    int lengthOfLongestSubstring(string s) {
    	int max = 0;
    	std::vector<int> charIndex(256,-1);
    	int m = 0;
    	for(int i = 0; i < s.size(); i++)
    	{
    		m = std::max(m,charIndex[s[i]]+1);
    		charIndex[s[i]] = i;
    		max = std::max(max,i - m + 1);
    	}
    	return max;
    }
};
