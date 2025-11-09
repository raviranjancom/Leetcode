class Solution {
public:
    int solve(int i,int j,int k){
        return abs(i-j)+abs(j-k)+abs(k-i);
    }
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> take(101);
        for(int i=0;i<nums.size();i++){
            take[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(int i=0;i<101;i++){
            if(take[i].size()==3){
                ans=min(ans,solve(take[i][0],take[i][1],take[i][2]));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
