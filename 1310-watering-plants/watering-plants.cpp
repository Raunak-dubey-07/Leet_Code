class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i=0;
        int n=plants.size();
        long long ans=0;
        int curr=capacity;
        while(i<n){
            if(curr>=plants[i]){
                ans++;
                curr-=plants[i];
            }
            else{
                curr=capacity;
                ans+=((i+1)*2-1);
                curr-=plants[i];
            }
            i++;
        }
        return ans;
    }
};