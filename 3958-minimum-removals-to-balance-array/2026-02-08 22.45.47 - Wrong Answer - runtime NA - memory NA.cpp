class Solution {
public:
    int minRemoval(vector<int>& nums, int k){
        int n=nums.size();
        int mini=1e9;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            pq.push(nums[i]);
        }
        int ans=0;
        while(!pq.empty() && pq.top()>mini*k){
            ans++;
            pq.pop();
        }
        return ans;
    }
};
