class Solution {
public:
    void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int idx){
        if(idx>=nums.size()){
            ans.push_back(ds);
            return ;
        }
        ds.push_back(nums[idx]);
        subset(nums, ans, ds, idx+1);
        ds.pop_back();
        subset(nums, ans, ds, idx+1);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int idx=0;
        subset(nums, ans, ds, idx);

        int x=0;
        for(auto it1:ans){
            int y=0;
            for(auto it2:it1){
                y=y^it2;
            }
            x=x+y;
        }
        return x;
    }
};
