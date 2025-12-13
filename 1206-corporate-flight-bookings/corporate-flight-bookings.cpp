class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int x=bookings.size();
        vector<int>prefix(n,0);
        for(int i=0;i<x;i++){
            for(int j=bookings[i][0];j<=bookings[i][1];j++){
                prefix[j-1]+=bookings[i][2];
            }
        }
        return prefix;
        
    }
};