class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans;
        for(int i=2*n-2;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i>=n){
                st.push(nums[i%n]);
            }
            else{
                if(st.empty()) ans.push_back(-1);
                else{
                    ans.push_back(st.top());
                }
                st.push(nums[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
