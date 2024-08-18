class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=size(nums);
        int f=-2147483640,s=-2147483640,t=-2147483640;
        for(int i=0;i<n;i++){
            if(f<nums[i]){
                t=s;
                s=f;
                f=nums[i];
            }
        }
        if(s==-2147483640 || t==-2147483640) return f;
        return t;
    }
};
