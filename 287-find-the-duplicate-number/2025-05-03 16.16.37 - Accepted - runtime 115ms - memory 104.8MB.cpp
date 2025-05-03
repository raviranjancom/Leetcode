class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto iterator : mp){
            if(iterator.second>1){
                return iterator.first;
            }
        }
        return 0;
    }
};
