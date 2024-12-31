class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=i+1;j<n;j++){
                int k=-1*(nums[i]+nums[j]);
                if(mp.find(k) != mp.end()){
                    vector<int> ds={nums[i], nums[j], k};
                    sort(ds.begin(),ds.end());
                    st.insert(ds);
                    mp[k]--;
                }
                mp[nums[j]]++;
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
