class Solution {
public:
    int countElements(vector<int>& nums, int k){
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        set<int> st(nums.begin(),nums.end());
        while(!pq.empty()){
            int ele=pq.top(); pq.pop();
            st.erase(ele);
            while(!pq.empty() && pq.top()==ele){
                pq.pop();
            }
            if(pq.size()>=k) ans++;
            else break;
        }
        return ans;
    }
};
