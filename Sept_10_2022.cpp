class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2,0)));
        
        // no need for base as dp is initialised with 0
                                      
        for(int i = n-1; i>=0; i--)
        {
            for(int cap = 1; cap<=k; cap++)
            {
                for(int buy = 0; buy<=1; buy++ )  // cap = 0 already covered in base cases.
                {
                    if(buy ==1)
                    {
                        dp[i][cap][buy] = max(-prices[i] + dp[i+1][cap][0], 0 + dp[i+1][cap][1]);
                    }
                    else
                    {
                        dp[i][cap][buy] = max(prices[i] + dp[i+1][cap-1][1], 0 + dp[i+1][cap][0]);
                    }
                }
            }
        }
        
        return dp[0][k][1];
    }
};
