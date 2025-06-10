class Solution {
public:
    int fun(vector<int> &nums, int goal){
        int n=nums.size();
        int l=0,r=0,ans=0,sum=0;
        if(goal<0){
            return 0;
        }
        while(l<n && r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k-1);
    }
};