class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<pair<int,int>> ds;
        int r=0;
        while(r<k){
            while(!ds.empty() && ds.back().first < nums[r]){
                ds.pop_back();
            }
            ds.push_back({nums[r], r});
            r++;
        }
        ans.push_back(ds.front().first);

        while(r<n){
            while(!ds.empty() && ds.back().first < nums[r]){
                ds.pop_back();
            }
            ds.push_back({nums[r], r});
            while(!ds.empty() && ds.front().second <= r-k){
                ds.pop_front();
            }

            ans.push_back(ds.front().first);
            r++;
        }
        return ans;
    }
};
