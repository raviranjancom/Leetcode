class Solution {
public:
    int minimumDifference(vector<int>& nums, int k){
        if(nums.size()==1) return 0;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=min(ans,abs(nums[j]-nums[i]));
            }
        }
        return ans;
    }
};
