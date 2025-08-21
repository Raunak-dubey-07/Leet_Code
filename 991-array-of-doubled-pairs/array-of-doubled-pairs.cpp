class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        // ans++;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            // cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
            if (arr[i] == 0 && mp[arr[i]] > 1){
                ans++;
            mp[2 * arr[i]]--;
            mp[arr[i]]--;
            }
            else if (mp[arr[i]] > 0 && arr[i]!=0) {
                if (mp[2 * arr[i]] > 0) {
                    cout << arr[i] << " " << mp[arr[i]] << endl;
                    ans++;
                    mp[2 * arr[i]]--;
                    mp[arr[i]]--;
                }
            }
        }
        if (ans >= n / 2) {
            return true;
        }
        return false;
    }
}
;