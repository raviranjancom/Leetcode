class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=1;
        ans.push_back(intervals[0]);
        while(i<n){
            if(ans.back()[1] >= intervals[i][0]){
                vector<int> x=ans.back();
                ans.pop_back();
                ans.push_back({min(intervals[i][0],x[0]), max(x[1],intervals[i][1])});
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
};
