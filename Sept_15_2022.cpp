class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> v;
         if(changed.size()%2==1)
            return {};
        
        map<int, int> mp;
        for(int x : changed)
            mp[x]++;
        for(auto x : mp)
        {
            int p = x.first;
            
            if(mp[p] == 0)
                continue;
            
            while(mp[p]>0)
            {
                v.push_back(p);
                mp[p]--;
                mp[2*p]--;
            }
            if(mp[p]<0)
            {
                return {};
            }
        }
        return v;
        
    }
};
