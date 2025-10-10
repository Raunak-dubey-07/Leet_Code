class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=0;
        sort(s.begin(),s.end());
        for(int i=0;i<n-1;i++){
            if(s[i]=='a'){
                continue;
            }
            int x=(s[i+1]-s[i]);
           ans+=x;
        }
        if(s[n-1]=='a'){
            return ans;
        }
        return ans+'z'+1-s[n-1];
        
    }
};