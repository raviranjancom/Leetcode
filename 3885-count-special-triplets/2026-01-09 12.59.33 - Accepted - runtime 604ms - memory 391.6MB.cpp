class Solution {
public:
    int specialTriplets(vector<int>& nums){
        int ans=0;
        int mod=1e9+7;
        unordered_map<long long,long long> mp1,mp2;
        for(auto &it:nums){
            if(it%2==0 && mp2[it/2]>0){
                ans=(ans+mp2[it/2])%mod;
            }
            if(mp1[2*it]>0){
                mp2[it]=(mp2[it]+mp1[2*it])%mod;
            }
            mp1[it]=(mp1[it]+1)%mod;
        }
        return ans%mod;
    }
};
