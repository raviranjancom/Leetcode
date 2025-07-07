class Solution {
public:
    int maze(int m, int n, int cr, int cc, int ans){
        if(cr==m && cc==n){
            return ans+1;
        }
        else if(cr==m && cc<n){
            return maze(m, n, cr, cc+1, ans);
        }
        else if(cr<m && cc==n){
            return maze(m, n, cr+1, cc, ans);
        }
        else{
            return maze(m, n, cr+1, cc, ans) + maze(m, n, cr, cc+1, ans);
        }
    }
    int uniquePaths(int m, int n) {
        int ans=0;
        return maze(m-1, n-1, 0, 0, ans);
    }
};
