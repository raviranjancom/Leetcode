class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int,int> frq;
        for(int i=0;i<nums.size();i++){
            frq[nums[i]]++;
        }
        vector<int> ans;
        for(auto it:frq){
            if(k>0) ans.push_back(it.first);
            else break;
            k--;
        }
        return ans;
    }
};