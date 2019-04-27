class Solution {
public:
    string longestPalindrome(string s) {
    	int start = 0;
    	int len = 1;
    	for(int i =  0; i < s.size()-1;i++)
    	{
    		extend(s,i,i,start,len);
    		extend(s,i,i+1,start,len);
    	}
    	return s.substr(start,len);
    }
private:
	void extend(const string& s, int l, int r, int& start,int& len)
	{
		while(l >=0 && r < s.size() && s[l] == s[r])
		{
			l--;
			r++;
		}
		if(r-l-1 > len)
		{
			start = l+1;
			len = r-l-1;
		}
	}
};
