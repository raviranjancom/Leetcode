class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n),suffix(n),ans(n);
        int x=1,y=1;
        for(int i=0;i<n;i++){
            x*=nums[i];
            prefix[i]=x;

            y*=nums[n-1-i];
            suffix[n-1-i]=y;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=suffix[i+1];
            }
            else if(i==n-1){
                ans[i]=prefix[i-1];
            }
            else{
                ans[i]=prefix[i-1]*suffix[i+1];
            }
        }
        return ans;
    }
};