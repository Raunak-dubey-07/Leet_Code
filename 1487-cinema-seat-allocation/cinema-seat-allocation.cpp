class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       unordered_map<int,vector<int>>mp;
       // int n=reservedSeats.size();
       int ans=0;
        for(auto r: reservedSeats){
            mp[r[0]].push_back(r[1]);
        }
        ans=(n-mp.size())*2;
        for(auto x:mp){
            bool flag=false;
            vector<bool>ele(11,0);
            for(int i:x.second){
                ele[i]=1;
            }
            if(!ele[2] &&!ele[3] &&!ele[4] &&!ele[5]){
                ans++;
                flag=true;
            }
            if(!ele[6] &&!ele[7] &&!ele[8] &&!ele[9] ){
                ans++;
                flag=true;
            }
            if(!flag)
            if(!ele[4] &&!ele[5] &&!ele[6] &&!ele[7]){
                ans++;
            }
        }
        return ans;
        
    }
};