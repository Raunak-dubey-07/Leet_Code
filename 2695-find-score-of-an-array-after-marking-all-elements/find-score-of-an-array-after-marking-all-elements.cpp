class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long score=0;
        unordered_map<int,bool>visited;
        while(!pq.empty()){
            int ele=pq.top().first;
            int idx=pq.top().second;
            //cout<<ele<<" "<<idx<<endl;

            if(!visited[idx]){
               //  cout<<ele<<" "<<idx<<endl;
                score=score+ele;
                visited[idx]=true;
                if((idx+1)<n){
               // cout<<idx+1<<endl;
                visited[idx+1]=true;
            }
             if((idx-1)>=0){
              //  cout<<idx-1<<endl;
                visited[idx-1]=true;
            }
            }
            
           // cout<<endl;
            pq.pop();
        }
        return score;
    }
};