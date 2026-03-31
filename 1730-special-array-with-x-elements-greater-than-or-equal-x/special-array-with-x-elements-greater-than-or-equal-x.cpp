class Solution {
public:
    int specialArray(vector<int>& nums) {
        int l=0;
        int r=1000;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(l<=r){
            int mid=(l+r)/2;
            int x=lower_bound(nums.begin(), nums.end(), mid)-nums.begin();
            cout<<mid<<" "<<x<<endl;
            if(mid == n - x){
            return mid;
        }
        else if(mid > n - x){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
        }
        return -1;

        
    }
};