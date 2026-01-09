class Solution {
public:
    int specialTriplets(vector<int>& nums){
        int ans=0;
        unordered_map<int,int> mp1,mp2;
        for(auto &it:nums){
            if(it%2==0 && mp2[it/2]>0){
                ans+=mp2[it/2];
            }
            if(mp1[2*it]>0){
                mp2[it]++;
            }
            mp1[it]++;
        }
        return ans;
    }
};
