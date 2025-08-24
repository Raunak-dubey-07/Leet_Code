class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int j=n-1;
        vector<int>ans;
        while(i<=j && i<n && j>=0){
            ans.push_back(nums[i]);
            i++;
            if(i<=j){
                ans.push_back(nums[j]);
                j--;
            }
        }
        return ans;
        
    }
};