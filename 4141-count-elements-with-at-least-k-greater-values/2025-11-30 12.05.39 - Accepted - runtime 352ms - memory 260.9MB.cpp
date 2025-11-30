class Solution {
public:
    int countElements(vector<int>& nums, int k){
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        unordered_map<int,int> mp;    // element => count

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(!pq.empty()){
            int ele=pq.top(); pq.pop();
            while(!pq.empty() && pq.top()==ele){
                pq.pop();
            }
            if(pq.size()>=k) ans+=mp[ele];
            else break;
        }
        return ans;
    }
};
