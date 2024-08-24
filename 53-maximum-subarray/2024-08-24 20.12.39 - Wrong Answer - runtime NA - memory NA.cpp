class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=size(nums);
        int s=0,m=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s<0) s=0;
            m=max(s,m);
        }
        return m;
    }
};
