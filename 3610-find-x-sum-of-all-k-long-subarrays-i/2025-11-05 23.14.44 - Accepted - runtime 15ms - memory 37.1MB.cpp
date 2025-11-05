class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int l=0,r=0;
        vector<int> ans;
        
        for(int i=0;i<n-k+1;i++){
            map<int,int> mp;
            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
            vector<pair<int,int>> ds;
            for(auto it:mp){
                ds.push_back({it.second,it.first});
            }
            sort(ds.begin(),ds.end(),greater<pair<int,int>>());
            int sum=0;
            for(int j=0;j<x && j<mp.size();j++){
                sum+=ds[j].first*ds[j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
