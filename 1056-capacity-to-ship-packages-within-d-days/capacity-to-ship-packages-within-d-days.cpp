class Solution {
public:
    bool check(vector<int>& weights, int days,long long mid){
        int d=1;
        long long sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if (weights[i] > mid) return false;
            sum+=weights[i];
            if(sum>mid){
                sum=weights[i];
                d++;
            }
        }
        if(d<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=accumulate(weights.begin(), weights.end(), 0);
        int ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(weights,days,mid)){
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