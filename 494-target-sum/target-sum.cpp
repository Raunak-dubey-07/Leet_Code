class Solution {
public:
   int solve(vector<int>& nums, int idx, int target, vector<vector<int>>& dp, int sum) {
        if (idx == nums.size()) {
            return target == 0;
        }

        int t_idx = target + sum;
        if (t_idx < 0 || t_idx > 2 * sum) return 0;

        if (dp[idx][t_idx] != -1) {
            return dp[idx][t_idx];
        }

        int plus = solve(nums, idx + 1, target - nums[idx], dp, sum);
        int minus = solve(nums, idx + 1, target + nums[idx], dp, sum);

        return dp[idx][t_idx] = plus + minus;
    }

   int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum) return 0;

    vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
    return solve(nums, 0, target, dp, sum);
}
};