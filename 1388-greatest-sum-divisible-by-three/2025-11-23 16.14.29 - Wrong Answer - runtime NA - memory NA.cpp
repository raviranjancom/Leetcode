class Solution {
public:
    int maxSumDivThree(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%3==0) return sum;
        int k=sum%3;
        for(int i=0;i<n;i++){
            if(nums[i]%3!=0 && nums[i]>=k) return sum-nums[i];
        }
        return sum;
    }
};
