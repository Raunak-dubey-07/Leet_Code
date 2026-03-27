class Solution {
public:
    bool check(long long n,vector<int>& batteries,long long mid){
        long long total=0;
        int m=batteries.size();
        
        for(int i=0;i<m;i++){
            total+=min(mid,1LL*batteries[i]);
           
        }
        return total>=n*mid;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=*min_element(batteries.begin(),batteries.end());
        long long r=(accumulate(batteries.begin(),batteries.end(),0LL))/n;
        cout<<r<<endl;
        long long ans=0;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(n,batteries,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }

        }
        return ans; 
    }
};