class Solution {
public:
    vector<vector<double>> dp;
    double solve(int poured, int row, int col){
        if(row<0 || col<0 || row<col){
            return 0;
        }
        if(row==0 && col==0) return poured;
        if(dp[row][col]!=-1) return dp[row][col];
        double left=(solve(poured,row-1,col-1)-1)/2.0;
        double right=(solve(poured,row-1,col)-1)/2.0;
        if(left<0) left=0.0;
        if(right<0) right=0.0;

        return dp[row][col]=left+right;
    }
    double champagneTower(int poured, int query_row, int query_glass){
        dp.resize(101,vector<double>(101,-1.0));
        return min(1.0,solve(poured,query_row,query_glass));
    }
};
