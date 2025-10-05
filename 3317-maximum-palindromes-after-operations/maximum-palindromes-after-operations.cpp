class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                mp[words[i][j]]++;
            }
        }
        int even=0;
        int odd=0;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
        for(auto x:mp){
            if(x.second%2==0){
                even+=x.second;
            }
            else{
                even+=x.second-1;
                odd++;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(words[i].size()%2==0){
                if(even>=words[i].size()){
                    even=even-words[i].size();
                    ans++;
                }
                
            }
            else{
                if(odd>0 && even>=words[i].size()-1){
                    odd--;
                    even=even-words[i].size()+1;
                    ans++;
                }
                else if(even>=words[i].size()){
                    even=even-words[i].size();
                    ans++;
                }
                
                
            }
        }
        return ans;
    }
};