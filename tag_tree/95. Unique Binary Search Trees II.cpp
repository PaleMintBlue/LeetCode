class Solution
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		if(n<1)
			return {};
		return generateTrees(1,n);
	}
	vector<TreeNode*> generateTrees(int start,int end)
	{
		vector<TreeNode*> ret;
		if(start>end)
		{
			ret.push_back(nullptr);
			return ret;
		}
		if(start==end)
		{
			ret.push_back(new TreeNode(start));
			return ret;
		}
		for(int i = start;i <= end;i++)
		{
			vector<TreeNode*> left = generateTrees(start,i-1);
			vector<TreeNode*> right = generateTrees(i+1,end);
			for(auto left_node:left)
			{
				for(auto right_node:right)
				{
					TreeNode* root = new TreeNode(i);
					root->left = left_node;
					root->right = right_node;
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
};