class Solution {
public:
    int minRemoval(vector<int>& nums, int k){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=lower_bound(nums.begin(),nums.end(),nums[i]*k);
            int dist=static_cast<int>(it-nums.begin()-i);
            ans=max(ans,n-dist-1);
        }
        return ans;
    }
};
