class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>open(n,0);
        vector<int>closed(n,0);
        if(customers[0]=='N'){
            closed[0]++;
        }
        if(customers[n-1]=='Y'){
            open[n-1]++;
        }
        for(int i=1;i<n;i++){
            if(customers[i]=='N'){
                closed[i]=1+closed[i-1];
            }
            else{
                closed[i]=closed[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(customers[i]=='Y'){
                open[i]=1+open[i+1];
            }
            else{
                open[i]=open[i+1];
            }
        }
        int res=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            int ans=0;
            if(i-1>=0){
                ans+=closed[i-1];
            }
            ans+=open[i];
            int prev=res;
            res=min(res,ans);
            if(res==ans && res!=prev){
                idx=i;
            }
        }
        int prev=res;
        res=min(res,closed[n-1]);
        if(res==closed[n-1] && res!=prev){
            idx=n;
        }
        return idx;
    }
};