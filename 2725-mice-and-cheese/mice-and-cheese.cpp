class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        vector<pair<int,int>>diff(n);
        for(int i=0;i<n;i++){
            diff[i]={reward1[i]-reward2[i],i};
        }
        sort(diff.begin(),diff.end(),greater<pair<int,int>>());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=reward2[i];
        }
        for(int i=0;i<k;i++){
            int idx=diff[i].second;
            ans=ans-reward2[idx];
            ans=ans+reward1[idx];
        }
        return ans;
    }
};