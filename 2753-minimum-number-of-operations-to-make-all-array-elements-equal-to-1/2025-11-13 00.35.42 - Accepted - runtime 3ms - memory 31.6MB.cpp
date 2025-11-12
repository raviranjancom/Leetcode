class Solution {
public:
    int GCD(int a,int b){
        return (b==0)?a:GCD(b,a%b);
    }
    int minOperations(vector<int>& nums) {
        int res=INT_MAX;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int ds=INT_MAX;
            for(int j=i;j<n;j++){
                if(ds==INT_MAX){
                    ds=nums[j];
                }
                else{
                    ds=GCD(ds,nums[j]);
                }
                if(ds==1){
                    res=min(res,j-i);
                }
            }
        }
        cout<<res;
        if(res==INT_MAX) return -1;
        int ans=(res==0)?0:-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                ans++;
            }
        }
        return ans+res;
    }
};
