class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
         int maxi=INT_MIN;
        int n=s.size();
        int i=0;int j=0;
        int count=0;
        int ans=0;
        while(j<n){
            count+=abs(t[j]-s[j]);
            while(count>maxCost){
                count-=abs(t[i]-s[i]);
                i++;
            }
            ans=max(ans,(j-i+1));

            j++;
        }
        return ans;
        
    }
};