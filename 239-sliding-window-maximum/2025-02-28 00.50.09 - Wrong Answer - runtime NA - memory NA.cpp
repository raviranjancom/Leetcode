class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> ds;
        vector<int> ans;
        int i=0;
        for(i=0;i<k;i++){
            while(!ds.empty() && ds.back().second < nums[i]){
                ds.pop_back();
            }
            if(ds.empty()){
                ds.push_back({i, nums[i]});
            }
            else if(ds.back().second > nums[i]){
                ds.push_back({i, nums[i]});
            }
        }
        ans.push_back(ds.front().second);

        if(ds.back().first <= i-k+1) ds.pop_front();
        for(i=k;i<n;i++){
            while(!ds.empty() && ds.back().second < nums[i]){
                ds.pop_back();
            }
            if(ds.empty()){
                ds.push_back({i, nums[i]});
            }
            else if(ds.back().second > nums[i]){
                ds.push_back({i, nums[i]});
            }
            
            ans.push_back(ds.front().second);
            if(ds.back().first <= i-k+1) ds.pop_front();
        }
        return ans;
    }
};

