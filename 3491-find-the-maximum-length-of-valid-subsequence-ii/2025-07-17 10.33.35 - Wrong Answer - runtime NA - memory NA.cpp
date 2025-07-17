class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int res=2;
        for(int j=0;j<n-1;j++){
            int prev=(nums[j] + nums[j+1])%k;
            int x=j+1;
            int ans=2;
            for(int i=j+2;i<n;i++){
                int parity=(nums[x]+nums[i])%k;
                if(parity==prev){
                    x=i;
                    ans++;
                    res=max(ans,res);
                    prev=parity;
                }
            }
        }
        return res;
    }
};
