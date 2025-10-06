class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int n=enemyEnergies.size();
        long long sum=currentEnergy;
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++){
            sum+=enemyEnergies[i];
            mini=min(mini,1LL*enemyEnergies[i]);
        }
        if(currentEnergy<mini){
            return 0;
        }
        sum=sum-mini;
        return sum/mini;
        //  sort(enemyEnergies.begin(), enemyEnergies.end());
        // if (c < enemyEnergies[0]) return 0;
        // long long a = c;
        // for( int j = e.size() - 1;j > 0; --j)  a += enemyEnergies[j];
        // return a / enemyEnergies[0];

        
    }
};