class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors){
        long long totalMax=0;
        long long r1=0,r2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                totalMax+=r2;
                r1=0;
                r2=0;
            }
            long long temp=max(r2,r1+nums[i]);
            r1=r2;
            r2=temp;
        }
        totalMax+=r2;
        return totalMax;
    }
};