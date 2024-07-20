class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                x=n-i;
                break;
            }
        }
        
        for(int i=0;i<x;i++){
            int t=nums[n-1];
            for(int j=1;j<n;j++){
                nums[n-j]=nums[n-j-1];
            }
            nums[0]=t;
        }
        // check sortted or not
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])
            return false;
        }
        return true;
    }
};