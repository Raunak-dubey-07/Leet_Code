class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        int n = logs.size();
        for (int i = 0; i < n; i++) {
                mp[logs[i][0]].insert(logs[i][1]);
        }
        vector<int>ans(k,0);
        for(auto x:mp){
            ans[x.second.size()-1]++;
        }
        return ans;
    }
};
