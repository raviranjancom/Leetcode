class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        // map to store the earliest index for each mod value
        unordered_map<int, int> seen;
        seen[0] = 0;

        for (int i = 1; i <= n; i++) {
            // Option 1: keep nums[i-1]
            if (dp[i - 1] != LLONG_MAX) {
                dp[i] = dp[i - 1] + nums[i - 1];
            }

            int mod = prefix[i] % k;
            if (seen.count(mod)) {
                int j = seen[mod];
                dp[i] = min(dp[i], dp[j]);
            }

            // only set first occurrence
            if (!seen.count(mod)) {
                seen[mod] = i;
            }
        }

        return dp[n];
    }
};
