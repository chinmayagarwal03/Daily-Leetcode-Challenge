class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans = to_string(root->val);
        if(root->left != NULL)
            ans += "("+ (tree2str(root->left)) + ")";
        
        if(root->right != NULL)
        {
            if(root->left == NULL)
                ans += "()";
            ans += "(" + (tree2str(root->right)) + ")";
        }
        
        return ans;
    }
};
