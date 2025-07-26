class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,sum=nums[l],len=INT_MAX;
        while(l<n && r<n){
            if(sum>=target){
                len=min(r-l+1,len);
                sum-=nums[l];
                l++;
            }
            else{
                r++;
                if(r<n) sum+=nums[r];
            }
        }
        return (len==INT_MAX)?0:len;
    }
};
