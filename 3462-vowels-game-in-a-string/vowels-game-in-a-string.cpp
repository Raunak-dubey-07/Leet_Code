class Solution {
public:
    bool doesAliceWin(string s) {
        bool vowel=false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='e'||s[i]=='o'){
                vowel=true;
                break;
            }

        }
        if(vowel){
            return true;
        }
        return false;
        
    }
};