class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        return (a[1]<b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int m=intervals[0][0],ans=0;
        for(int i=0;i<n;i++){
            if(m<=intervals[i][0]){
                m=intervals[i][1];
            }
            else ans++;
        }
        return ans;
    }
};
// m=0
// [[1,2],[1,3],[2,3],[3,4]]
// 0<=1 \U0001f44d m=2 i=1  ans=0
// 1<=2 \U0001f44e m=2 i=2  ans=1
// 2<=2 \U0001f44d m=3 i=3  ans=1
// 3<=3 \U0001f44d m=4 i=4  ans=1