class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>diff;
        vector<pair<int,int>>mp;
        int n=costs.size();
        int ans=0;
        for(int i=0;i<n;i++){
            diff.push_back(abs(costs[i][0]-costs[i][1]));
            mp.push_back({abs(costs[i][0]-costs[i][1]),i});
        }
        sort(mp.begin(),mp.end(),greater<pair<int,int>>());
        int one=n/2;
        int two=one;
        for(int i=0;i<mp.size();i++){
            int a=costs[mp[i].second][0];
            int b=costs[mp[i].second][1];
            if(min(a,b)==a){
                if(one>0){
                ans+=a;
                one--;
                }
                else{
                    ans+=b;
                    two--;
                }
            }
            else{
                if(two>0){
                    ans+=b;
                    two--;
                }
                else{
                    ans+=a;
                    one--;
                }
            }
        }
        return ans;
    }
};