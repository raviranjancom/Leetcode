class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(hash[i]==2) ans.push_back(i);
        }
        return ans;
    }
};