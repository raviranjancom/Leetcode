class Solution {
public:
    int numOfWays(int n) {
        long long aba=6;
        long long abc=6;
        int mod=1e9+7;
        // we start from row 2 beacuse row 1 is already set
        for(int i=2;i<=n;i++){
            long long new_aba=(3*aba + 2*abc)%mod;
            long long new_abc=(2*aba + 2*abc)%mod;

            aba=new_aba;
            abc=new_abc;
        }
        return  (aba + abc)%mod;
    }
};

// Method I : 
// class Solution {
// public:
//     int MOD=1e9+7;
//     int solve(vector<vector<int>> &grid,int num,int max_num){
//         int row=num/3;
//         int col=num%3;
//         if(num>=max_num){
//             return 1;
//         }
//         int ans=0;
//         for(int c=0;c<3;c++){
//             grid[row][col]=c;
//             if(check(grid,row,col)){
//                 ans=(ans+solve(grid,num+1,max_num))%MOD;
//             }
//         }
//         return ans;
//     }
//     bool check(vector<vector<int>> &grid, int cr, int cc){
//         if(cr>0 && grid[cr][cc]==grid[cr-1][cc]){
//             return false;
//         }
//         if(cc>0 && grid[cr][cc]==grid[cr][cc-1]){
//             return false;
//         }
//         return true;
//     }
//     int numOfWays(int n){
//         vector<vector<int>> grid(n,vector<int>(3,-1));
//         // 0 -> red
//         // 1 -> yellow
//         // 2 -> green
//         return solve(grid,0,3*n);
//     }
// };
