class Solution {
public:
    int specialTriplets(vector<int>& nums){
        int ans=0;
        unordered_map<int,int> mp;
        for(auto &it:nums){
            mp[it]++;
        }
        for(auto &it:mp){
            if(mp[2*it.first]>1){
                ans++;
            }
        }
        return ans;
    }
};
