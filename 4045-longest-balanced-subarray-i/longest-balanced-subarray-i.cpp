class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> arr(n);
            unordered_map<int, int> mp;
            if (nums[i] % 2 == 0) {
                arr[i].first = 1;
            } else {
                arr[i].second = 1;
            }
            mp[nums[i]]++;
            for (int j = i; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (nums[j] % 2 == 0) {
                    if (!mp[nums[j]]) {
                        // cout<<"!mpeven"<<endl;
                        arr[j].first = arr[j - 1].first + 1;
                        arr[j].second = arr[j - 1].second;
                    } else {
                        // cout<<"mpeven"<<endl;
                        arr[j].first = arr[j - 1].first;
                        arr[j].second = arr[j - 1].second;
                    }
                } else {
                    if (!mp[nums[j]]) {
                        // cout<<"!mpodd"<<endl;
                        arr[j].second = arr[j - 1].second + 1;
                        arr[j].first = arr[j - 1].first;
                    } else {
                        // cout<<"mpodd"<<endl;
                        arr[j].second = arr[j - 1].second;
                        arr[j].first = arr[j - 1].first;
                    }
                }

                if (arr[j].first == arr[j].second) {
                    ans = max(ans, j - i + 1);
                }
                mp[nums[j]]++;
            }
        }
        return ans==INT_MIN?0:ans;
    }
};