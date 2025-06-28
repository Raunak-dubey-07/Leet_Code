class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> suffixmaxsum(n, 0);
        vector<long long> suffixminsum(n, 0);
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, 1LL * (nums[i]));
            suffixmaxsum[i] = maxi;

            mini = min(mini, 1LL * (nums[i]));
            suffixminsum[i] = mini;
        }
        if (m == 1) {
            return max(suffixmaxsum[0] * suffixmaxsum[0],
                       suffixminsum[0] * suffixminsum[0]);
        }
        long long ans = LLONG_MIN;
        for (int i = 0; i < n - m + 1; i++) {
            if (nums[i] <= 0) {
                ans = max(ans, nums[i] * suffixminsum[i + m - 1]);
            } else {
                ans = max(ans, nums[i] * suffixmaxsum[i + m - 1]);
            }
        }
        return ans;
    }
};