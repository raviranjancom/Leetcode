class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int m=queries[0].size();
        vector<bool> ans;
        for(int i=0;i<n;i++){
            bool t=true;
            for(int j=queries[i][0];j<queries[i][1];j++){
                if((nums[j]%2==0 && nums[j+1]%2==1) || (nums[j]%2==1 && nums[j+1]%2==0)) continue;
                else{
                    t=false;
                    break;
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
