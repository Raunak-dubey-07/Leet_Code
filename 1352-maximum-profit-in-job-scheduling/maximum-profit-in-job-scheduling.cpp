class Solution {
public:
vector<long long> dp;
    int getnext(vector<pair<int,pair<int,int>>>&tym,int i,int end,int n){
        int r=n-1;
        int l=i;
        int res=n+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(tym[mid].first>=end){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
    int solve(vector<pair<int,pair<int,int>>>&tym,int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int s=tym[i].first;
        int e=tym[i].second.first;
        int p=tym[i].second.second;
        int next=getnext(tym,i+1,e,n);
        int inc=tym[i].second.second+solve(tym,next,n);
        int ex=solve(tym,i+1,n);
        return dp[i]=max(inc,ex);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>tym;
        int n=profit.size();
        for(int i=0;i<n;i++){
            tym.push_back({startTime[i],{endTime[i],profit[i]}});
        }
         dp.resize(n,-1);
        sort(tym.begin(),tym.end());
        int start=tym[0].first;
        int end=tym[0].second.first;
        return solve(tym,0,n);
    }
};