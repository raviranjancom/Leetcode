class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> ds;
                int k=nums[i]+nums[j];
                k*=-1;
                if(mp.find(k)==mp.end()) continue;
                else{
                    if((nums[i]==k && nums[j]!=k && mp[k]>1) ||(nums[j]==k && nums[i]!=k && mp[k]>1) || (k!=nums[i] && k!=nums[j] && mp[k]>0) || (k==nums[i] && k==nums[j] && mp[k]>2)){
                        ds.push_back(nums[i]);
                        ds.push_back(nums[j]);
                        ds.push_back(k);
                        sort(ds.begin(),ds.end());
                    }
                    st.insert(ds);
                }
                
            }
        }
        for(auto it:st){
            if(it.size()==0) continue;
            else ans.push_back(it);
        }
        return ans;
    }
};