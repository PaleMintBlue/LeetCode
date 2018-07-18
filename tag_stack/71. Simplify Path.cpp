class Solution {
public:
    string simplifyPath(string path)
	{
		std::vector<std::string> stack;
		std::string res,tmp;
		std::istringstream iss(path);
		while(std::getline(iss,tmp,'/'))
		{
			if(tmp.empty()|| tmp ==".")
				continue;
			if(tmp==".."&&!stack.empty())
				stack.pop_back();
			else if(tmp!="..")
				stack.push_back(tmp);
		}
		for(const auto& str:stack)
		{
			res += "/" + str;
		}
		return res.empty()? "/" : res;
	}
};