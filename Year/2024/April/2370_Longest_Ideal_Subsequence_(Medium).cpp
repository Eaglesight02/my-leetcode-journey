class Solution {
public:
    // MLE
    // int longestIdealSubsequence(string& s, int ind, int prev, int k, unordered_map<int, unordered_map<int, int>>& dp) {
    //     if (ind == s.size()) {
    //         return 0;
    //     }
        
    //     if (dp.count(ind) && dp[ind].count(prev)) {
    //         return dp[ind][prev];
    //     }
        
    //     int take = 0, notTake = 0;
    //     notTake = longestIdealSubsequence(s, ind + 1, prev, k, dp);
        
    //     if (prev == -1 || abs(s[ind] - s[prev]) <= k) {
    //         take = 1 + longestIdealSubsequence(s, ind + 1, ind, k, dp);
    //     }
        
    //     return dp[ind][prev] = max(take, notTake);
    // }
    
    // int longestIdealString(string s, int k) {
    //     unordered_map<int, unordered_map<int, int>> dp;
    //     return longestIdealSubsequence(s, 0, -1, k, dp);
    // }




    
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for (auto& i : s) {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }







};