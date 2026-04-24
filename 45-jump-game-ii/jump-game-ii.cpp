class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int currend=0;
        int jump=0;
        int maxi=0;
        int i=0;
        while(i<n-1){
            while(i<=currend){
                maxi=max(maxi,i+nums[i]);
                i++;
            }
            jump++;
            if(maxi>=n-1){
                return jump;
            }
            currend=maxi;
        }
        return 0;
        
    }
};