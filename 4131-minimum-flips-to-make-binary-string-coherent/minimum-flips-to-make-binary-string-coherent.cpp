class Solution {
public:
    int minFlips(string s) {
        int one=0;
        int zero=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
        }
        if(s[0]=='1' && s[n-1]=='1'){
            return max(0,min(zero,one-2));
        }
        return max(0,min(zero,one-1));
    }
};