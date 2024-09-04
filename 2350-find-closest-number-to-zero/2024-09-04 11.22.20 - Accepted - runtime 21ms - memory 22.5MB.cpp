class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n=size(nums);
        int m=INT_MAX,v,t;
        for(int i=0;i<n;i++){
            t=nums[i];
            if(t<0){
                t*=-1;
            }
            if(m>t){
                m=t;
                v=i;
            }
        }
        int a=nums[v];
        if(a<0) a*=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==a) return nums[i];
        }
        return nums[v];
    }
};
 