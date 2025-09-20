class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mini=INT_MAX;
        int n=candies.size();

        long long sum=0;
        for (int candy : candies) sum += candy;
        if(sum<k){
            return 0;
        }
        int low=1;
        int high=high = *max_element(candies.begin(), candies.end());;
        while(low<high){
            long long total=0;
            int mid=(low+high+1)/2;
            for(auto candy:candies){
                total+=candy/mid;
            }
            if(total>=k){
                low=mid;
            }
            else{
                high=mid-1;
            }

        }
        return low;


        
    }
};