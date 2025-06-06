class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>>vec;
        //unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=nums[i];
            int sum=0;
            while(k){
                sum=sum+k%10;
                k=k/10;

            }
            vec.push_back({sum,nums[i]});
        }
        sort(vec.begin(),vec.end());
        int maxi=-1;
        for(int i=0;i<n-1;i++){
            if(vec[i].first==vec[i+1].first){
                maxi=max(maxi,(vec[i].second+vec[i+1].second));
            }

        }
        return maxi;
        
    }
};