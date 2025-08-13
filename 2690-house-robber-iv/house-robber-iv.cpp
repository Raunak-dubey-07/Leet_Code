class Solution {
public:
    int possible(vector<int>& nums, int mid, int k) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= mid) {
                k--;
                i = i + 2;
            } else {
                i++;
            }
            if (k == 0) {
                return true;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;
        int e = *max_element(nums.begin(), nums.end());
        while (s < e) {
            int m = (s + e) / 2;
            if (possible(nums, m, k)) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return e;
    }
};