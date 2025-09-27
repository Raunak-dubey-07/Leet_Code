class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        targetFriend = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++) {
            if (!pq.empty() && times[i][0] >= pq.top().first) {
                vector<pair<int, int>> arr;
                while (!pq.empty() && times[i][0] >= pq.top().first) {
                    arr.push_back({pq.top().first, pq.top().second});
                    pq.pop();
                }

                sort(arr.begin(), arr.end(),
                     [](const pair<int, int>& a, const pair<int, int>& b) {
                         return a.second < b.second;
                     });
                pq.push({times[i][1], arr[0].second});
                for (int i = 1; i < arr.size(); i++) {
                    pq.push({arr[i].first, arr[i].second});
                }
                if (targetFriend == times[i][0]) {
                    return arr[0].second;
                }
            } else {
                pq.push({times[i][1], pq.size()});
                if (targetFriend == times[i][0]) {
                    // cout<<"hii"<<endl;
                    return pq.size() - 1;
                }
            }
        }
        return 0;
    }
}
;