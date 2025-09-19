class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int st=0;
        int ed=n-1;
        while(st<n && s[st]=='0'){
            st++;
        }
        while(ed>=0 && s[ed]=='1'){
            ed--;
        }
        long long currzero=0;
        long long  b=st;
        long long sw=0;
        while(st<=ed){
            if(s[st]=='0'){
                sw+=(st-b-currzero);
                currzero++;

            }
            st++;
        }
        return sw; 
        
    }
};