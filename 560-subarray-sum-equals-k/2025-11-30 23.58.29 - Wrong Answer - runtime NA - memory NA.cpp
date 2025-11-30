class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        if(k==0) return 0;
        int n=nums.size();
        int ans=0,sum=0;
        int l=-1,r=-1;
        while(l<n && r<n){
            if(sum<k){
                r++;
                sum+=nums[r];
            }
            else{
                sum-=(l==-1)?0:nums[l];
                l++;
            }
            if(sum==k){
                ans++;
                r++;
                if(r<n) sum+=nums[r];
            }
        }
        return ans;
    }
};