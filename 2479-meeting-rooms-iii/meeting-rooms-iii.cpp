class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long> last(n, 0);
        vector<long long> ans(n, 0);
        for (int i = 0; i < m; i++) {
            long long st = meetings[i][0];
            long long end = meetings[i][1];
            long long d = end - st;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (last[i] <= st) {
                    last[i] = end;
                    ans[i]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                long long idx = -1;
                long long early = LLONG_MAX;
                for (int i = 0; i < n; i++) {
                    int prev = early;
                    early = min(early, last[i]);
                    if (early == last[i] && early != prev) {
                        idx = i;
                    }
                }
                last[idx] += d;
                ans[idx]++;
            }
        }
        long long maxi=LLONG_MIN;
        int idx=-1;
        for (int i = 0; i < n; i++) {
            int prev=maxi;
            maxi=max(maxi,ans[i]);
            if(ans[i]==maxi && maxi!=prev){
                idx=i;
            }
           
        }
        return idx;
    }
};