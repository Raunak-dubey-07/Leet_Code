class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mp;
        int n=responses.size();
        for(int i=0;i<n;i++){
            unordered_map<string,int>visited;
            for(int j=0;j<responses[i].size();j++){
                if(!visited[responses[i][j]]){
                    visited[responses[i][j]]=1;
                    mp[responses[i][j]]++;
                }
            }
        }
            int freq=INT_MIN;
            string s="A";
            for(auto &x:mp){
                int prev=freq;
                freq=max(x.second,freq);
                if(freq==x.second && freq==prev){
                    s=min(s,x.first);
                }
                else if(freq==x.second){
                    s=x.first;
                }

            }
            return s;
    }
};