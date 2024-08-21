class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=size(nums);
        int t=0,ans=0,x=nums[0];
        for(int i=1;i<n;i++){
            if(t==0) x==nums[i];
            if(x==nums[i]) t++;
            if(x!=nums[i] && t>0) t--;
            if(ans<t) ans=t;
        }
        return x;
    }
};