class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=size(nums);
        int f=-2147483648,s=-2147483648,t=-2147483648;
        for(int i=0;i<n;i++){
            if(f<nums[i]){
                t=s;
                s=f;
                f=nums[i];
            }
        }
        if(s==-2147483648 || t==-2147483648) return f;
        return t;
    }
};
