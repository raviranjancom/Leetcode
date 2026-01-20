class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums){
        int n=nums.size();
        vector<int> ans(n);
        unordered_map<int,pair<int,int>> mp;
        for(int i=999;i>0;i--){
            mp[((i+1)|(i))]={i+1,i};
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans[i]=mp[nums[i]].second;
            }
            else{
                ans[i]=-1;
            }
        }
        return ans;
    }
};
