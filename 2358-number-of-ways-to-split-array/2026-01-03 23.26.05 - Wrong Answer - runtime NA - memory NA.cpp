class Solution {
public:
    int waysToSplitArray(vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            int left=nums[i];
            int right=nums[n-1]-nums[i];
            if(left>right){
                ans++;
            }
        }
        return ans;
    }
};
