class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        string p="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                p.push_back(s[i]);
            }

        }
        return stoll(p);
        
    }
};