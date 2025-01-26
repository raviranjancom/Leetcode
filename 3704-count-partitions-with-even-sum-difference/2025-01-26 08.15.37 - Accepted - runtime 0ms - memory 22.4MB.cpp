class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0,sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=sum-left;
            (left - right)%2 == 0 ? ans++ : ans=ans; 
        }
        return ans;
    }
};