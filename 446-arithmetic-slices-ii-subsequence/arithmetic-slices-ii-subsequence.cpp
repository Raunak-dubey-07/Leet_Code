class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long long,int>> mp(n);
        long long result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                int j_count=0;
                if(it!=end(mp[j])){
                    j_count=it->second;
                }
                mp[i][diff]+=j_count+1;
                result+=j_count;
            }
        }
        return result;
        
    }
};