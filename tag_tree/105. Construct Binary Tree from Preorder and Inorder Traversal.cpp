/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
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