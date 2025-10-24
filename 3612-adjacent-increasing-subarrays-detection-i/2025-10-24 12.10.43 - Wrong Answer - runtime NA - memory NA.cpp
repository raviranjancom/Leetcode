class Solution {
public:
    bool check(vector<int>& nums, int k,int x){
        for(int i=x+1;i<x+k;i++){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n-2*k-1;i++){
            if(check(nums,k,i) && check(nums,k,i+k)) return true;
        }
        return false;
    }
};
