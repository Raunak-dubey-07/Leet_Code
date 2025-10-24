class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int o=0;
        int c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(c>0){
                    if(o>0){
                        ans++;
                        o--;
                    }
                    else{
                    ans+=(c/2);
                    if(c%2!=0){
                        ans+=2;
                    }
                    }
                    c=0;
                }
                o++;
            }
            else{
                c++;
                if(o>0 && c==2){
                    o--;
                    c=0;
                }
               
            }
        }
        if(o>0 && c>0){
            int x=min(o,c);
            o-=x;
            c-=x;
            ans+=x;
        }
        if(o>0){
            ans+=2*o;
        }
        if(c>0){
            ans=ans+(c/2);
            if(c%2!=0){
                ans+=2;
            }
        }
        return ans;
    }
};