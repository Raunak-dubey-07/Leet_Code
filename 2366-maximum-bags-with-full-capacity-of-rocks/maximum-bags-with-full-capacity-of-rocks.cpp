class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diff;
        int n=rocks.size();
        for(int i=0;i<n;i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        int full=0;
        for(int i=0;i<n;i++){
            if(diff[i]==0){
                full++;
            }
            else{
                if(additionalRocks>=diff[i]){
                    full++;
                    additionalRocks-=diff[i];
                }
                else{
                    break;
                }
            }
        }
        return full;
        
    }
};