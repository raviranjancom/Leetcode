class Solution {
public:
    int minOperations(vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        reverse(nums.begin(),nums.end());
        int ans=0;
        while(mp.size()!=nums.size()){
            ans++;
            for(int i=0;i<3;i++){
                if(mp.size()==0) return ans;
                mp[nums.back()]--;
                if(mp[nums.back()]==0) mp.erase(nums.back());
                nums.pop_back();
            }
        }
        return ans;
    }
};
// 8 5 6 
// mp.size == 4