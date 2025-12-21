class Solution {
public:
    long long minCost(string s, vector<int>& cost){
        int n=s.length();
        unordered_map<char,long long> mp;
        long long total=0;
        for(int i=0;i<n;i++){
            total+=cost[i];
            mp[s[i]]+=cost[i];
        }
        long long ans=9223372036854775801;
        for(auto ele:mp){
            ans=min(ans,total-ele.second);
        }
        return ans;
    }
};
