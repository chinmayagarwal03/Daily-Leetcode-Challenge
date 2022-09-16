
#Recursive code
int answer_recur(vector<int> &nums, vector<int> &multi, int i, int l, int r){

	if(i==multi.size())
		return 0;

	int first = multi[i]*nums[l] + answer_recur(nums, multi, i+1, l+1, r);
	int right = multi[i]*nums[r] + answer_recur(nums, multi, i+1, l, r-1);

	return max(first, right);
}

int maximumScore(vector<int>& nums, vector<int>& multi) {

	return answer_recur(nums, multi, 0, 0, nums.size()-1);
}
};

# Memoisation Code
class Solution {
public:
    int helper(int i1,int i, int j,vector<int>& n, vector<int>& m,  vector<vector<int>>&dp)
    {
         if(i1==m.size())
             return 0;
        if(dp[i1][i] !=-1)
            return dp[i1][i];
        int first = n[i]*m[i1] + helper(i1+1,i+1, j, n, m, dp);
        int second = n[j]* m[i1] + helper(i1+1, i,j-1, n, m, dp);
        return dp[i1][i]=max(first, second);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1, -1));
        return helper(0, 0, n-1,nums, multipliers , dp);
    }
   
   
   # Tabulation Code
  class Solution {
public:
    int maximumScore(vector<int>& v, vector<int>& m) {
        
        vector<vector<int>> dp(m.size()+1, vector<int>(m.size()+1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][dp[0].size()-1] = 0;
            dp.back()[i] = 0;
        }
        for(int i = dp.size()-2; i >= 0; i--) {
            for(int j = dp[0].size()-2; j >=0; j--) {
                dp[i][j] = max(m[i]*v[j] + dp[i+1][j+1],
                                    m[i]*v[v.size()-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
