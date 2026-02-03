class Solution {
public:
void solve(vector<int>&candidates,int i,int target,vector<int>&ans,vector<vector<int>>&result){
    cout<<i<<" i "<<endl;
    if(target==0){
        result.push_back(ans);
        return;
    }
    if(target<0|| i>=candidates.size()){
        return;
    }
    ans.push_back(candidates[i]);
    if(i<candidates.size())
    solve(candidates,i,target-candidates[i],ans,result);
    ans.pop_back();
    if(i+1<candidates.size())
    solve(candidates,i+1,target,ans,result);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        solve(candidates,0,target,ans,result);
        return result;
    }
};