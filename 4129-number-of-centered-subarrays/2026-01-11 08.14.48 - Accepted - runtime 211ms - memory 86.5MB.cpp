class Solution {
public:
    int centeredSubarrays(vector<int>& nums){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            int sum=0;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                sum+=nums[j];
                if(mp.find(sum)!=mp.end()) ans++;
            }
        }
        return ans;
    }
};
