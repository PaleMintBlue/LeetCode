class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        int i = 0;
        for(;i<len;i++)
            if(s[i]!=' ')
                break;
        if(s[i]=='+'||s[i]=='-')
            i++;
        int numOfNum = 0;
        int numOfPoint = 0;
        for(;i<len&&((s[i]>='0'&&s[i]<='9')||s[i]=='.');i++)
        {
            if(s[i]=='.')
                numOfPoint++;
            else
                numOfNum++;
        }
        if(numOfNum<1||numOfPoint>1)
            return false;
        if(s[i]=='e')
        {
            i++;
            if(s[i]=='+'||s[i] == '-')
                i++;
            int numOfNum = 0;
            for(;s[i]>='0'&&s[i]<='9';i++,numOfNum++){}
            if(numOfNum<1)
                return false;
        }
        for(;s[i] == ' ';i++){}
        if(i==len)
            return true;
        else
            return false;
        
    }
};