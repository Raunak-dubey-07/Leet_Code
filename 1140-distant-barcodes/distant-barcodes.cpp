class Solution {
public:
struct CompareSecond {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second < b.second; 
    }
};
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        int n=barcodes.size();
        for(int i=0;i<n;i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareSecond> pq;
        for(auto x:mp){
            pq.push(x);
        }
        vector<int>ans;
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            if(!pq.empty()){
                pair<int,int>q=pq.top();
                pq.pop();
                ans.push_back(p.first);
                ans.push_back(q.first);
                q.second--;
                p.second--;
                if(q.second!=0){
                    pq.push(q);
                }
                if(p.second!=0){
                    pq.push(p);
                }
            }
            else{
                ans.push_back(p.first);
                p.second--;
                if(p.second!=0){
                    pq.push(p);
                }
            }
            
        }
        return ans;
        
    }
};