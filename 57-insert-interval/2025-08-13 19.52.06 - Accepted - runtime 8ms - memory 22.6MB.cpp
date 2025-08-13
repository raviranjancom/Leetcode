class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        if(n==0) return intervals;
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int wait=intervals[0][1];
        for(int i=1;i<n;i++){
            if(wait>=intervals[i][0]){
                vector<int> t=ans.back();
                ans.pop_back();
                ans.push_back({t[0],max(intervals[i][1],t[1])});
            }
            else{
                ans.push_back(intervals[i]);
            }
            wait=ans.back()[1];
        }
        return ans;
    }
};
// [[1,2],[3,5],[6,7],[8,10],[12,16] + [4,8]]
// [[1,2],[3,7],[8,10],[12,16]]
// m>=intervals[i][0] => 2>=3 m=2 i=1 \U0001f44e
// [[1,2],[3,5],[4,8],[6,7],[8,10],[12,16]]
// 5>4 m=5 i=1 \U0001f44d
// [[1,2],[3,8],[6,7],[8,10],[12,16]]
// m=8