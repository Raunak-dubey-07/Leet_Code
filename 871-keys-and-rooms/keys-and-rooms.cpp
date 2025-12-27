class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        vector<int>visited(n,false);
        q.push(0);
        int total=1;
        visited[0]=true;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(rooms[x].size()==0){
                continue;
            }
            for(auto key:rooms[x]){
                if(!visited[key]){
                    q.push(key);
                    visited[key]=true;
                    total++;
                }
            }
        }
        return total==n;

        
    }
};