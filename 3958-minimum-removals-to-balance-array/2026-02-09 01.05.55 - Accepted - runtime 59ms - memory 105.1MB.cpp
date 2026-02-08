class Solution {
public:
    int minRemoval(vector<int>& nums, int k){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1e9;
        for(int i=0;i<n;i++){
            int idx=upper_bound(nums.begin(),nums.end(),1LL*nums[i]*k)-begin(nums);
            int count=idx-i;
            ans=min(ans,n-count);
        }
        return ans;
    }
};
// 1 2 6 9
