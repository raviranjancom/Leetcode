class Solution {
public:
    bool pacific(vector<vector<int>>& heights, vector<vector<int>>& dp, int cr, int cc) {
        int n = heights.size(), m = heights[0].size();
        if (cr < 0 || cc < 0) return true; // reached Pacific
        if (dp[cr][cc] != -1) return dp[cr][cc];

        dp[cr][cc] = 0; // mark as visiting (prevents cycles)
        int curr = heights[cr][cc];

        // Check all 4 directions if valid flow (non-increasing)
        if ((cr > 0 && heights[cr - 1][cc] <= curr && pacific(heights, dp, cr - 1, cc)) ||
            (cc > 0 && heights[cr][cc - 1] <= curr && pacific(heights, dp, cr, cc - 1)) ||
            (cr == 0 || cc == 0)) {
            return dp[cr][cc] = 1;
        }

        if ((cr + 1 < n && heights[cr + 1][cc] <= curr && pacific(heights, dp, cr + 1, cc)) ||
            (cc + 1 < m && heights[cr][cc + 1] <= curr && pacific(heights, dp, cr, cc + 1))) {
            return dp[cr][cc] = 1;
        }

        return dp[cr][cc] = 0;
    }

    bool atlantic(vector<vector<int>>& heights, vector<vector<int>>& dp, int cr, int cc) {
        int n = heights.size(), m = heights[0].size();
        if (cr >= n || cc >= m) return true; // reached Atlantic
        if (dp[cr][cc] != -1) return dp[cr][cc];

        dp[cr][cc] = 0; // visiting
        int curr = heights[cr][cc];

        if ((cr + 1 < n && heights[cr + 1][cc] <= curr && atlantic(heights, dp, cr + 1, cc)) ||
            (cc + 1 < m && heights[cr][cc + 1] <= curr && atlantic(heights, dp, cr, cc + 1)) ||
            (cr == n - 1 || cc == m - 1)) {
            return dp[cr][cc] = 1;
        }

        if ((cr - 1 >= 0 && heights[cr - 1][cc] <= curr && atlantic(heights, dp, cr - 1, cc)) ||
            (cc - 1 >= 0 && heights[cr][cc - 1] <= curr && atlantic(heights, dp, cr, cc - 1))) {
            return dp[cr][cc] = 1;
        }

        return dp[cr][cc] = 0;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific_dp(n, vector<int>(m, -1));
        vector<vector<int>> atlantic_dp(n, vector<int>(m, -1));
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific(heights, pacific_dp, i, j) && atlantic(heights, atlantic_dp, i, j)) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
