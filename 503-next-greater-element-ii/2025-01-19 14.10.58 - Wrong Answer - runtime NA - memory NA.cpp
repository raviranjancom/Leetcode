class Solution {
public:
    vector<int> reverse(vector<int> v){
        int n=v.size();
        int a=0,b=n-1;
        while(a<=b){
            int t=v[a];
            v[a]=v[b];
            v[b]=t;
            a++;
            b--;
        }
        return v;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n-1;i++){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            st.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
                st.push(nums[i]);
            }
            else{
                ans.push_back(st.top());
                st.push(nums[i]);
            }
        }
        return reverse(ans);
    }
};
