class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ele=INT_MAX;
        for(int x:nums){
            ele=min(ele,x);
        }
        long long ans=0;
        for(int x:nums){
            ans+=x-ele;

        }
        return ans;
    }
};