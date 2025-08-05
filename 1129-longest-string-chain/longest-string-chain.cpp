class Solution {
public:
    bool check(string&s1,string&s2){
        int c=0;
        if(s1.size()>s2.size()){
            string temp=s1;
            s1=s2;
            s2=temp;
        }
        cout<<s1<<" "<<s2<<endl;
        int i=0;
        int j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
                j++;
                c++;
            }
            else{
            i++;
            j++;
            }
            if(c>1){
                return false;
            }
        }
        if(c>1){
            return false;
        }
        cout<<"yes"<<endl;
        return true;
    }
    int solve(vector<string>&words,int idx,int prev,vector<vector<int>>&dp){
        if(idx>=words.size()){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int inc=0;
        if (prev == -1 || 
    (abs((int)words[prev].size() - (int)words[idx].size()) == 1 && check(words[prev], words[idx])))
{
            inc=1+solve(words,idx+1,idx,dp);  
        }
        int ex=solve(words,idx+1,prev,dp);
            return dp[idx][prev+1]=max(inc,ex);
    }
    int longestStrChain(vector<string>& words) {
        vector<pair<int,string>>s;
        for(int i=0;i<words.size();i++){
            s.push_back({words[i].size(),words[i]});
        }
        sort(s.begin(),s.end());
        vector<string>dupwords(words.size());
        cout<<"hii"<<endl;
        for(int i=0;i<s.size();i++){
            dupwords[i]=s[i].second; 
        }
        for(int i=0;i<dupwords.size();i++){
            cout<<dupwords[i]<<endl;
        }
        int n=words.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(dupwords,0,-1,dp);
    }
};