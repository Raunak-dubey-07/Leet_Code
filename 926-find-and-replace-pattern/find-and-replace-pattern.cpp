class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        int n=words.size();
        int m=pattern.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            unordered_map<char,int>mp1;
            for(int j=0;j<m;j++){
                mp[words[i][j]]=pattern[j];
                mp1[pattern[j]]=words[i][j];
            }
            bool match=true;
            for(int j=0;j<m;j++){
                if(mp[words[i][j]]!=pattern[j] || mp1[pattern[j]]!=words[i][j]){
                    match=false;
                    break;
                }
            }
            if(match){
                ans.push_back(words[i]);
            }

        }
        return ans;
    }
};