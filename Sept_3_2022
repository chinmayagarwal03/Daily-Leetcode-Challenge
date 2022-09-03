class Solution {
public:
    void dfs(int num, int n, int k,vector<int>& ans)
    {
        if(n == 0)
            ans.push_back(num);
        else
        {
            int digit = num%10;
            
            if(digit + k <=9)
            {
                dfs(num*10 + digit + k, n-1, k, ans);
            }
            
            if(k!=0 && digit>=k)
                dfs(num*10 + digit -k, n-1, k, ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int num = 1; num<=9; num++)
        {
            dfs(num, n-1, k, ans);
        }
        return ans;
    }
};
