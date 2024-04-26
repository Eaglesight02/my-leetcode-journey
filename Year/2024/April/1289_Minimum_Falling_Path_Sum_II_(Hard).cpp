class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // Base case: initialize the first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }
        
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + grid[i][j]);
                    }
                }
            }
        }
        
        // Find the minimum in the last row
        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, dp[n-1][j]);
        }
        
        return minPathSum;
    }
};