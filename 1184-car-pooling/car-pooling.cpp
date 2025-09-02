class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // compare 2nd column
    });
     priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
    int c=0;
    int n=trips.size();
    for(int i=0;i<n;i++){
       // c+=trips[i][0];
       while(!pq.empty() && pq.top().first<=trips[i][1]){
        c=c-pq.top().second;
        pq.pop();
       }
       pq.push({trips[i][2],trips[i][0]});
       c+=trips[i][0];
       if(c>capacity){
        cout<<c<<endl;
        return false;
       }
    }
    return true;
    }
};