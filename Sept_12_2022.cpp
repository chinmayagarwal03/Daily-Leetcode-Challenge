class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int res  = 0;
        int s =0;
        int i = 0;
        int j = tokens.size() - 1;
        while(i<=j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                i++;
                s++;
                res = max(res, s);
            }
            
            else if(s>=1)
            {
                power += tokens[j];
                j--;
                s--;
            }
            else
                break;
        }
        
        return res;
    }
};
