class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=happiness[i]-i;
            ans+=max(x,0);
            k--;
            if(k==0){
                break;
            }
        }
        return ans;
        
    }
};