class Solution {
public:
    string largestPalindromic(string num) {
        int n=num.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[num[i]-'0']++;
        }
        string ans="";
        bool odd=false;
        int oddvalue=-1;
        for(int i=9;i>=0;i--){
            if(i==0 && ans.size()==0){
                continue;
            }
            for(int j=0;j<mp[i]/2;j++){
                ans.push_back(i+'0');
            }
            if(mp[i]%2!=0 && !odd){
                oddvalue=i;
                odd=true;
            }
        }
        string res=ans;
        if(oddvalue!=-1)
        res.push_back(oddvalue+'0');
        reverse(ans.begin(),ans.end());
        res=res+ans;
        if(res.size()==0){
            return "0";
        }
        return res;

        
    }
};