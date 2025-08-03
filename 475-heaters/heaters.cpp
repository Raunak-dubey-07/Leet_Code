class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        int m=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int j=0;
        int rad=0;
        for(int i=0;i<n;i++){
            while(j<m-1&&abs(heaters[j]-houses[i])>=abs(heaters[j+1]-houses[i])){
                j++;
            }
            rad=max(rad,abs(heaters[j]-houses[i]));
        }
        return rad;
        
    }
};