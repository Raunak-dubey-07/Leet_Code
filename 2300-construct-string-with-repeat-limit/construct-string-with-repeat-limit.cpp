class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<int>pq;
        priority_queue<int>pq1;
        map<char,int>mp;
        string ans="";
        int n=s.size();
        sort(s.begin(),s.end(),greater<int>());
        int i=0;
        while(i<n){
            if(mp[s[i]]<repeatLimit){
                ans.push_back(s[i]);
                mp[s[i]]++;
                i++;
            }
            else{
                int j=i;
                while(s[j]==s[i]){
                    pq.push(s[j]);
                    j++;
                }
                i=j;
                while(!pq.empty() && i<n){
                    ans.push_back(s[i]);
                    int k=0;
                    while(!pq.empty() && k!=repeatLimit){
                    ans.push_back(pq.top());
                    pq.pop();
                    k++;
                    }
                    i++;
                    if(i==n && !pq.empty()){
                        return ans;
                    }
                }
            }
        }
        return ans;

        
    }
};