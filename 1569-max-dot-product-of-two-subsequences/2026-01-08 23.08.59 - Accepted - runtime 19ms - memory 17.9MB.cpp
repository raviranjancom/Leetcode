class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums1, vector<int>& nums2,int i, int j, int n,int m){
        if(i>=n || j>=m){
            return -1e9;
        }
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int x=nums1[i]*nums2[j];
        int y=nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1,n,m);
        int z=solve(nums1,nums2,i,j+1,n,m);
        int t=solve(nums1,nums2,i+1,j,n,m);

        return dp[i][j]=max(max(x,y),max(z,t));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size(),m=nums2.size();
        dp.resize(n,vector<int>(m,INT_MIN));
        return solve(nums1,nums2,0,0,n,m);
    }
};
