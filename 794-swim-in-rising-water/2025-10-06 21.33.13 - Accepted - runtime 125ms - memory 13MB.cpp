class Solution {
public:
    void solve(vector<vector<int>>& grid, vector<vector<bool>>& mark,
               vector<vector<int>>& dp, int cr, int cc, int n, int m, int &ds, int ans) {
        // out of bound
        if (cr < 0 || cr > n || cc < 0 || cc > m) return;

        ans = max(ans, grid[cr][cc]);

        // pruning using memoization
        if (ans >= dp[cr][cc]) return;
        dp[cr][cc] = ans;

        // reached destination
        if (cr == n && cc == m) {
            ds = min(ds, ans);
            return;
        }

        mark[cr][cc] = true;

        // explore neighbors
        if (cr > 0 && !mark[cr - 1][cc])
            solve(grid, mark, dp, cr - 1, cc, n, m, ds, ans);

        if (cr < n && !mark[cr + 1][cc])
            solve(grid, mark, dp, cr + 1, cc, n, m, ds, ans);

        if (cc > 0 && !mark[cr][cc - 1])
            solve(grid, mark, dp, cr, cc - 1, n, m, ds, ans);

        if (cc < m && !mark[cr][cc + 1])
            solve(grid, mark, dp, cr, cc + 1, n, m, ds, ans);

        mark[cr][cc] = false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> mark(n, vector<bool>(m, false));
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        int ds = INT_MAX;
        solve(grid, mark, dp, 0, 0, n - 1, m - 1, ds, INT_MIN);
        return ds;
    }
};
