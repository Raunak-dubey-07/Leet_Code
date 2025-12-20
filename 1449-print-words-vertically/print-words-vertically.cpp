class Solution {
public:
    vector<string> printVertically(string s) {
        int c=0;
        int ans=0;
        int n=s.size();
        int r=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                r++;
                ans=max(c,ans);
                c=0;
            }
            c++;
        }

        ans=max(c,ans);
        int j=0;
        int k=0;
        vector<vector<char>>matrix(r,vector<char>(ans,' '));
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                j++;
                k=0;
            }
            else{
            matrix[j][k++]=s[i];
            }
        }
        vector<string>str;
        for(int i=0;i<ans;i++){
            string s;
            for(int j=0;j<r;j++){
                s.push_back(matrix[j][i]);
            }
            s.erase(s.find_last_not_of(' ') + 1);
            if(s.size()>0)
            str.push_back(s);
        }
        return str;



        
    }
};