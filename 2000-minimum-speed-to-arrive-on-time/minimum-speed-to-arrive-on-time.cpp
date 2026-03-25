class Solution {
public:
    int check(vector<int>& dist, double hour,long long mid){
        int n=dist.size();
        double total=0;
        for(int i=0;i<n;i++){
            total+=(dist[i]/mid);
            if(i==n-1){
                // cout<<(double)dist[i]/(double)mid<<endl;
                total+=(((double)dist[i]/(double)mid)-(dist[i]/mid));
                // cout<<total<<endl;
                break;
            }
            if(dist[i]%mid!=0){
                total++;
            }
            // cout<<total<<endl;
        }
        // cout<<total<<endl;
        if(total<=hour){
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long l=1;
        long long r=1e10;
        long long ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            // cout<<"mid "<<mid<<endl;
            if(check(dist,hour,mid)){ 
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        } 
        return ans;     
    }
};