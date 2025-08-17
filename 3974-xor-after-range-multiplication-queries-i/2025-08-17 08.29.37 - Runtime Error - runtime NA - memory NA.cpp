class Solution {
public:
    int calculate(vector<int> &nums){
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            ans=(ans^nums[i]);
        }
        return ans;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1000000007;
        int n=queries.size();
        for(int i=0;i<n;i++){
            while(queries[i][0]<=queries[i][1]){
                nums[queries[i][0]]=(nums[queries[i][0]]*queries[i][3])%mod;
                queries[i][0]+=queries[i][2];
            }
        }
        return calculate(nums);
    }
};
