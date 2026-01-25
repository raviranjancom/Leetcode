class Solution {
public:
    int minimumPrefixLength(vector<int>& nums){
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                ans=i;
            }
        }
        return ans+1;
    }
};
