class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
        int n=profit.size();
        int m=worker.size();
        for(int i=0;i<n;i++){
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int i=n-1;
        int j=m-1;
        int ans=0;
        while(j>=0 && i>=0){
            cout<<worker[j]<<" "<<v[i].second<<endl;
            if(worker[j]>=v[i].second){
                ans=ans+v[i].first;
                j--;
            }
            else{
                i--;
            }
        }
        return ans;
        
    }
};