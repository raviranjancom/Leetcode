class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxval=0,minval=0;
        for(int i=0;i<n;i++){
            int pmax=0,nmax=0;
            for(int j=i;j<n;j++){
                pmax+=nums[j];
                nmax+=nums[j];
                maxval=max(pmax,maxval);
                minval=min(nmax,minval);
            }
            
        }

        if(abs(maxval) > abs(minval)) return abs(maxval);
        return abs(minval);
    }
};
// -1 -2 