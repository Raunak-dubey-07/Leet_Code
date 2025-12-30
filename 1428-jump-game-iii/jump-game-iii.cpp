class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>q;
        vector<int>visited(n,0);
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(arr[front]==0){
                return true;
            }
            if(front+arr[front]<n && !visited[arr[front]+front]){
                q.push(front+arr[front]);
                visited[arr[front]+front]=true;
            }
            if(front-arr[front]>=0 && !visited[front-arr[front]]){
                q.push(front-arr[front]);
                visited[front-arr[front]]=true;
            }
        }
        return false;
    }
};