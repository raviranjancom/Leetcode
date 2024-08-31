class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=0;
        int n=size(nums);
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                x=x^nums[i];
            }
        }
        return x;
    }
};
