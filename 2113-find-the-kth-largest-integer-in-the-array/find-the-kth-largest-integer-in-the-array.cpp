class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int,string>>pq;
        for(string s:nums){
            pq.push({s.size(),s});
        }
        while(k>1){
            //cout<<pq.top().second<<endl;
            pq.pop();
            k--;
        }
        return (pq.top().second); 
    }
};