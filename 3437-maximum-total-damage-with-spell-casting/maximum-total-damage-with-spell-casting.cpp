class Solution {
public:
     long long solve(vector<pair<long long,long long>>&damage,int i,vector<long long>&dp){
        if(i>=damage.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int j=i;
        while(j<damage.size()&&damage[j].first<=damage[i].first+2 ){
            j++;
        }
        long long take=damage[i].first*damage[i].second+solve(damage,j,dp);
        long long non_take=solve(damage,i+1,dp);
        return dp[i]=max(take,non_take);
    }
    long long maximumTotalDamage(vector<int>& power) { 
        int n=power.size();
        sort(power.begin(),power.end());
        int c=1;
        vector<pair<long long,long long>>damage;
        for(int i=0;i<n-1;i++){
            if(power[i]==power[i+1]){
                c++;
            }
            else{
                damage.push_back({power[i],c});
                c=1;
            }
        }
        damage.push_back({power[n-1],c});
        vector<long long>dp(damage.size()+1,-1);
        return solve(damage,0,dp);
    }
};