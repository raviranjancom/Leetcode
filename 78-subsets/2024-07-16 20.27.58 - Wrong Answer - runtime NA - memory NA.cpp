class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        int i,j;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                vector<int> t;
                vector<int> tp;
                if(i==j) t.push_back(nums[i]);
                if(j>i){
                    tp.push_back(nums[i]);
                    tp.push_back(nums[j]);
                }
                if(j>i){
                    for(int k=i;k<=j;k++){
                        t.push_back(nums[k]);
                    }
                }
                st.insert(tp);
                st.insert(t);
            }
        }
        for(auto a:st){
            ans.push_back(a);
        }
        return ans;
    }
};