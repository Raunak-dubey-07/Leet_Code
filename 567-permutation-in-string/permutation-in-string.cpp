class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int w=s1.size();
        int n=s2.size();
        sort(s1.begin(),s1.end());
        for(int i=0;i<n;i++){
            string s=s2.substr(i,w);
            sort(s.begin(),s.end());
            if(s==s1){
                return true;
            }
        }
        return false;

    }
};