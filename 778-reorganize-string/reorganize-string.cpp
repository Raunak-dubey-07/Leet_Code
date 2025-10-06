class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
         priority_queue<pair<char,int>, vector<pair<char,int>>, 
                   function<bool(pair<char,int>, pair<char,int>)>> pq(
        [](pair<char,int> a, pair<char,int> b) {
            return a.second < b.second; // max-heap by second
        }
    );
        for(auto x:mp){
            pq.push(x);
        }
        string ans="";
        while(pq.size()>1){
            pair<char,int>x=pq.top();
            pq.pop();
            pair<char,int>y=pq.top();
            pq.pop();
            ans.push_back(x.first);
            ans.push_back(y.first);
            if(x.second-1>0){
                x.second--;
                pq.push(x);
            }
             if(y.second-1>0){
                y.second--;
                pq.push(y);
            }
        }
        cout<<ans<<endl;
        cout<<pq.size()<<endl;
        if(!pq.empty() && pq.top().second>1){
            return "";
        }
        if(!pq.empty() && ans.size()>0 && pq.top().second==ans[ans.size()-1]){
            return "";
        }
        if(pq.size()>0)
        return ans+pq.top().first;
        return ans;
    }
};