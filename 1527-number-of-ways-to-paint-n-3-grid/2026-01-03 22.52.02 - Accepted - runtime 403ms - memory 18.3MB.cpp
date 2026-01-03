class Solution {
public:
int mod=1e9+7;
    vector<string> states={"RYR","YRY","GRY","RYG","YRG","GRG","RGR","YGR","GYR","RGY","YGY","GYG"};
    vector<vector<int>> dp;
    int solve(int n,int prev){
        if(n==0) return 1;
        if(dp[n][prev]!=-1) return dp[n][prev];

        string last=states[prev];
        int ans=0;
        for(int i=0;i<12;i++){
            string curr=states[i];
            bool conflict=false;
            for(int c=0;c<3;c++){
                if(last[c]==curr[c]){
                    conflict=true;
                }
            }
            if(!conflict){
                ans=(ans+solve(n-1,i))%mod;
            }
        }
        return dp[n][prev]=ans;
    }
    int numOfWays(int n){
        dp.resize(n,vector<int>(12,-1));
        int ans=0;
        for(int i=0;i<12;i++){
            ans=(ans+solve(n-1,i))%mod;
        }
        return ans;
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

// Method II :
// class Solution {
// public:
//     int numOfWays(int n) {
//         long long aba=6;
//         long long abc=6;
//         int mod=1e9+7;
//         // we start from row 2 beacuse row 1 is already set
//         for(int i=2;i<=n;i++){
//             long long new_aba=(3*aba + 2*abc)%mod;
//             long long new_abc=(2*aba + 2*abc)%mod;

//             aba=new_aba;
//             abc=new_abc;
//         }
//         return  (aba + abc)%mod;
//     }
// };
