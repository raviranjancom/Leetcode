class Solution {
public:
    int add(int n){
        return n*(n+1)/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        while(l<n && r<n){
            if(nums[r]!=0){
                ans+=add(r-l);
                r++;
                l=r;
            }
            else{
                r++;
            }
        }
        ans+=add(r-l);
        return ans;
    }
};
