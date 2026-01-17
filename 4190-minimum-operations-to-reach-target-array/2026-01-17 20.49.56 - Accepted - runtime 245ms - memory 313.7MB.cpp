class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target){
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &it:mp){
            bool flag=false;
            for(int idx:it.second){
                if(target[idx]==nums[idx]){
                    continue;
                }
                else{
                    flag=true;
                    nums[idx]=target[idx];
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};