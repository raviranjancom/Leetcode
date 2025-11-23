class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // Initialize states. 
        // 0 is possible for remainder 0 (empty sum).
        // Others are impossible initially.
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for (int num : nums) {
            vector<int> temp = dp; // Create a copy to store updates
            
            // Iterate through the 3 previous remainders (0, 1, 2)
            for (int i = 0; i < 3; i++) {
                
                // If the previous state is valid (not INT_MIN)
                if (dp[i] != INT_MIN) {
                    int sum = dp[i] + num;
                    int remainder = sum % 3;
                    
                    // We check if this new sum is better than what was 
                    // previously stored for this specific remainder
                    temp[remainder] = max(temp[remainder], sum);
                }
            }
            // Update the main dp array for the next number
            dp = temp; 
        }

        // We want the maximum sum with remainder 0
        return dp[0]; 
    }
};