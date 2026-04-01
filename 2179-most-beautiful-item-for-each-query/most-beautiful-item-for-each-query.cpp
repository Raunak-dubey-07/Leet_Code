class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> ans;
        int n = queries.size();
         for(int i = 1; i < items.size(); i++) {
        items[i][1] = max(items[i][1], items[i-1][1]);
    }
        for (int i = 0; i < n; i++) {
            int x = upper_bound(items.begin(), items.end(), queries[i],
                                [](int val, const vector<int>& a) {
                                    return val < a[0];
                                }) -
                    items.begin();
            if (x == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(items[x - 1][1]);
            }
        }
        return ans;
    }
};