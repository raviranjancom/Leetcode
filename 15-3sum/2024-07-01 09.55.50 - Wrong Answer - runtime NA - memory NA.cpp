class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> t;
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                    }
                }
                if(t.size()!=0){
                    sort(t.begin(),t.end());
                    st.insert(t);
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};