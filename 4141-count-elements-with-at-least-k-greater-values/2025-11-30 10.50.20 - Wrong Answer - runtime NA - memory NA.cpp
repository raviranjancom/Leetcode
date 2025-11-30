class Solution {
public:
    int max(int a,int b){
        if(a>b) return a;
        return b;
    }
    int countElements(vector<int>& nums, int k){
        set<int> st(nums.begin(),nums.end());
        return max(st.size()-k,0);
    }
};
