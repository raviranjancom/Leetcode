void fun(vector<int> &nums,set<vector<int>> &st){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> ds;
                    ds.push_back(nums[i]);
                    ds.push_back(nums[j]);
                    ds.push_back(nums[k]);
                    sort(ds.begin(),ds.end());
                    st.insert(ds);
                }
            }
        }
    }
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        fun(nums,st);
        for(auto j:st){
            ans.push_back(j);
        }
        
        return ans;
    }
};
