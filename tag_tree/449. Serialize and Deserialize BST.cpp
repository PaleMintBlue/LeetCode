/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> preorder;
        serialize(root,preorder);
        std::stringstream result;
        std::copy(preorder.begin(),preorder.end(),std::ostream_iterator<int>(result," "));
        return result.str();

    }
    
    void serialize(TreeNode* root,vector<int>& preorder)
    {
        if(!root)
            return;
        preorder.push_back(root->val);
        serialize(root->left,preorder);
        serialize(root->right,preorder);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        vector<int> preorder;
        stringstream ss(data);
        int value;
        while(ss>>value)
        {
            preorder.push_back(value);
        }
        vector<int> inorder(preorder.begin(),preorder.end());
        std::sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);        
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size())
            return nullptr;
        if(preorder.empty())
            return nullptr;
        return buildTree(preorder,0,preorder.size()-1,
                        inorder,0,inorder.size()-1);
        
    }
    
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,
                       vector<int>& inorder,int inStart,int inEnd)
    {
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        root->left = root->right = nullptr;
        if(preStart==preEnd)
        {
            if(inStart==inEnd&&preorder[preStart]==inorder[inStart])
            {
                return root;
            }else
                return nullptr;
        }
        int mid = inStart;
        while(mid<=inEnd)
        {
            if(inorder[mid]==rootValue)
                break;
            mid++;
        }
        if(mid==inEnd&&inorder[mid]!=rootValue)
            return nullptr;
        int leftLength = mid - inStart;
        int rightLength = inEnd - mid;
        
        if(leftLength>0)
            root->left = buildTree(preorder,preStart+1,preStart+leftLength,
                                  inorder,inStart,mid-1);
        if(rightLength>0)
            root->right = buildTree(preorder,preStart+leftLength+1,preEnd,
                                   inorder,mid+1,inEnd);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));