class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int busy=customers[0][0];
        double waiting=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            busy=max(busy+customers[i][1],customers[i][1]+customers[i][0]);
            cout<<busy<<endl;
            waiting+=(busy-customers[i][0]);
        }
        return waiting/n;
        
    }
};