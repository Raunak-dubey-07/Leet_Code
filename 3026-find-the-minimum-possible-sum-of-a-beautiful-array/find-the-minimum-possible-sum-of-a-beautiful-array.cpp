class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        unordered_map<long long,bool>mp;
        int c=0;
         int i=1;
         long long ans=0;
        while(i<=(target/2) && c<n){
                ans+=i;    
                i++;
                c++;
        }
        i=target;
        while(c<n){
            ans+=i;
            c++;
            i++;
        }
        return ans%1000000007;
        
    }
};