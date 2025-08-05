class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int a=s.size();
        for(int i=s.size()-1;i>=1;i--){
            if(s[i]<s[i-1]){
                s[i-1]--;
                a=i;
            }
        }
        for(int i=a;i<s.size();i++){
            s[i]='9';
        }
        return stoi(s);
        
    }
};