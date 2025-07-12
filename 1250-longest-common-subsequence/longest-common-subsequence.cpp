class Solution {
public:
    int solve(string& text1, string& text2, int idx1, int idx2,
              vector<vector<int>>& dp) {
        if (idx1 >= text1.size() || idx2 >= text2.size()) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        if (text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] =
                       1 + solve(text1, text2, idx1 + 1, idx2 + 1, dp);
        }

        else {
            int a = solve(text1, text2, idx1, idx2 + 1, dp);
            int b = solve(text1, text2, idx1 + 1, idx2, dp);
            return dp[idx1][idx2] = max(a, b);
        }
    }
    int solveTab(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();
        //vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                }

                else {
                    curr[j] = max(curr[j + 1], next[j]);
                }
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTab(text1, text2);
    }
};