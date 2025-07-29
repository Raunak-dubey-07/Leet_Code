class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0;
        int sum2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) {
            if (n1 * 1 > n2 * 6)
                return -1;
        }
        if (n2 > n1) {
            if (n2 * 1 > n1 * 6)
                return -1;
        }
        for (int i = 0; i < n1; i++) {
            sum1 += nums1[i];
        }
        for (int i = 0; i < n2; i++) {
            sum2 += nums2[i];
        }
        if (sum1 == sum2) {
            return 0;
        }
        vector<int> diff;
        int ans = 0;
        int gap = abs(sum1 - sum2);
        if (sum1 > sum2) {
            for (int i = 0; i < n1; i++) {
                diff.push_back(nums1[i] - 1);
            }
            for (int i = 0; i < n2; i++) {
                diff.push_back(6 - nums2[i]);
            }
            sort(diff.begin(), diff.end(), greater<int>());
            for (int i = 0; i < diff.size(); i++) {
                if (gap <= 0) {
                    break;
                }
                gap = gap - diff[i];
                ;
                ans++;
            }
            return ans;

        } else {
                for (int i = 0; i < n2; i++) {
                    diff.push_back(nums2[i] - 1);
                }
                for (int i = 0; i < n1; i++) {
                    diff.push_back(6 - nums1[i]);
                }
                sort(diff.begin(), diff.end(), greater<int>());
                for (int i = 0; i < diff.size(); i++) {
                    if (gap <= 0) {
                        break;
                    }
                    gap = gap - diff[i];
                    ;
                    ans++;
                }
                return ans;
        }
    }
};