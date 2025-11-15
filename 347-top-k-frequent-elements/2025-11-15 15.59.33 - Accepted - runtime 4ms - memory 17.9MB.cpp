class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int,int> frq;
        vector<int> ans;
        priority_queue<pair<int,int>> heap;
        for(int i=0;i<nums.size();i++){
            frq[nums[i]]++;
        }
        
        for(auto &it:frq){
            heap.push({it.second,it.first});
        }
        
        while(k--){
            auto x=heap.top(); heap.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};
