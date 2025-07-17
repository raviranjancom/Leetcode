class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int prev=(nums[0] + nums[1])%k;
        int x=1;
        int ans=2;
        for(int i=2;i<n;i++){
            int parity=(nums[x]+nums[i])%k;
            if(parity==prev){
                x=i;
                ans++;
                prev=parity;
            }
        }
        return ans;
    }
};
