class Solution {
public:
    int minimumDifference(vector<int>& nums, int k){
        int n=nums.size();
        if(k==1) return 0;
        sort(nums.begin(),nums.end());
        int i=0,j=k-1;
        int ans=1e9;
        while(j<n){
            ans=min(ans,nums[j]-nums[i]);
            j++; i++;
        }
        return ans;
    }
};
// 1 4 7 9
