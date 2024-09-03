class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=size(nums);
        for(int i=1;i<n;i++){
            int a=nums[i-1]%2;
            int b=nums[i]%2;
            if(a==b) return false;
        }
        return true;
    }
};