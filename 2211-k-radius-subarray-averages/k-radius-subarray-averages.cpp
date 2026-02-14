class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i<k || i+k>=n){
                // cout<<"a "<<i<<endl;
                ans.push_back(-1);
            }
            else{
                if(i-k-1<0){
                    ans.push_back(prefix[i+k]/(2*k+1));
                }
                else{
                    // cout<<i<<endl;
                    // cout<<i+k<<" "<<i-k-1<<endl;
                    ans.push_back((prefix[i+k]-prefix[i-k-1])/(2*k+1));
                }
            }

        }
        return ans;

        
    }
};