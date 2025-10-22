class Solution {
public:
    int solve(vector<int>& nums, int k, int m,int n){
        // The range of values of elements already equal to target
        int lb=lower_bound(nums.begin(),nums.end(),n)-nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),n)-nums.begin();

        // The range of values of elements that can be converted to target
        int LB=lower_bound(nums.begin(),nums.end(),(long long)n-k)-nums.begin();
        int UB=upper_bound(nums.begin(),nums.end(),(long long)n+k)-nums.begin();

        return (ub-lb) + min(m,(UB-ub+lb-LB));    // The elements already equal to target + the elements range that can be converted to target
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            ans=max(ans,solve(nums,k,numOperations,nums[i]));
            ans=max(ans,solve(nums,k,numOperations,nums[i]+k));
            ans=max(ans,solve(nums,k,numOperations,nums[i]-k));
        }
        return ans;
    }
};