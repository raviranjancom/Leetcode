class Solution {
public:
    bool solve(vector<int> nums, int i, int d){
        while(i>=0 && i<nums.size()){
            if(nums[i]>0){
                nums[i]--;
                d=d*(-1);
            }
            i+=d;
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]>0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && solve(nums,i,1)==true) ans++;
            if(nums[i]==0 && solve(nums,i,-1)==true) ans++;
        }
        return ans;
    }
};
