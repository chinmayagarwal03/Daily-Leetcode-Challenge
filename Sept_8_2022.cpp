 
class Solution {
public:
     vector<int> res;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
     inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        inorder(root);
       
        return res;
    }
};
