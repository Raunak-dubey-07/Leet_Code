class Solution {
public:
    bool take(vector<int>& bloomDay, int m, int k,long long mid){
        int n=bloomDay.size();
        int i=0;
        int ad=0;
        int boq=0;
        while(i<n){
            if(bloomDay[i]<=mid){
                ad++;
                if(ad==k){
                    boq++;
                    ad=0;
                }
            }
            else{
                ad=0;
            }
            i++;
        }
        if(boq>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=0;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(take(bloomDay,m,k,mid)){
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