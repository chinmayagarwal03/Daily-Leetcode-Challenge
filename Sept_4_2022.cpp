class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y= p.second.second;
            
            mp[x][y].insert(node->val);
            
            if(node->left != NULL)
            {
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right != NULL)
            {
                q.push({node->right, {x+1, y+1}});
            }
        }
        
        vector<vector<int>>ans;
        
        for(auto p : mp)
        {
            vector<int>cols;
            for(auto b : p.second)
            {
                cols.insert(cols.end(), b.second.begin(), b.second.end());
            }
            ans.push_back(cols);
        }
        return ans;
    }
};
