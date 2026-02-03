class Solution {
public:
    bool isTrionic(vector<int>& nums){
        int n=nums.size();
        int i=0;
        for(i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) continue;
            else break;
        }
        int p=i;
        if(i==n-1 || i==0) return false;
        for(i=i;i<n-1;i++){
            if(nums[i]>nums[i+1]) continue;
            else break;
        }
        if(i==n-1 || i==p) return false;
        for(i=i;i<n-1;i++){
            if(nums[i]>nums[i+1]) continue;
            else break;
        }
        if(nums[n-2]>=nums[n-1]) return false;
        return true;
    }
};
