class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i<s.size(); i++)
        {
            v.push_back({e[i], s[i]});
        }
        sort(v.begin(), v.end());
        long ans = 0, sum =0;
        for(int i = n-1; i>=0; i--)
        {
            sum += v[i].second;
            pq.push(v[i].second);
            
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            
            ans = max( ans, sum * v[i].first);
        }
        
        return ans%mod;
    }
};
