class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(),ans=0;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i] < nums[j]+nums[k] && nums[j] < nums[i]+nums[k] && nums[k] < nums[j]+nums[i]){
                    ans=max(ans, nums[i]+nums[j]+nums[k]);
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};