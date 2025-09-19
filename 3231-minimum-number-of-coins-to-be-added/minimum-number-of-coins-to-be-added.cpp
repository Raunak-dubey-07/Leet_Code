class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=coins.size();
        int maxi=0;
        int i=0;
        int add=0;
        sort(coins.begin(),coins.end());
        while(maxi<target){
            if(i<n && coins[i]<=maxi+1){
                maxi+=coins[i];
                i++;
            }
            else{
                maxi+=maxi+1;
                add++;
            }
            
        }
        return add;
        
        
    }
};