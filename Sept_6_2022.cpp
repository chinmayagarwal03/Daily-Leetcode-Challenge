class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return root;
        root->left =  pruneTree(root->left);
        root->right =  pruneTree(root->right);
        
        if(root->left == NULL && root->right == NULL 
          && root->val == 0)
            return NULL;
        
        return root;
    }
};
