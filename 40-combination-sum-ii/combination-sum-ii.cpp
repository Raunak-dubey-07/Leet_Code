class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> ans,
               vector<vector<int>>& res, int i) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }
        ans.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, res, i + 1);
        ans.pop_back();
        while (i+1<candidates.size() && candidates[i + 1] == candidates[i]) {
            i++;
        }
        solve(candidates,target,ans,res,i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        vector<vector<int>>res;
        solve(candidates,target,ans,res,0);
        return res;
    }
};