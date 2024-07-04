class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto j:mp){
            if(j.second==1){
                ans=j.first;
                break;
            }
        }
        return ans;
    }
};