class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sumRow1=0, sumRow2=0, ans=LONG_LONG_MAX, robot2Sum=0;
        int n=grid[0].size();
        for(int i=0;i<n;i++){
            sumRow1+=grid[0][i];
        }
        
        for(int i=0;i<grid[0].size();i++){
            sumRow1-=grid[0][i];

            robot2Sum= max(sumRow1, sumRow2);

            ans=min(robot2Sum, ans);

            sumRow2+=grid[1][i];
        }
        return ans;
    }
};
