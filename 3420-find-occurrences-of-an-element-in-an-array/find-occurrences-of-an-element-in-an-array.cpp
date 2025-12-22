class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>occ(100001,-1);
        int freq=0;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                freq++;
                occ[freq]=i;
            }

        }
        for(int i=0;i<queries.size();i++){
            ans.push_back(occ[queries[i]]);
        }
        return ans;
    }
};