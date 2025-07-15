class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int ans=0;
        int c=1;
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                c++;
            }
            else{
                if(c%2!=0){
                    ans++;
                }
                c++;
            }
        }
        return ans;


    }
};