class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,bool>mp;
        int m=banned.size();
        for(int i=0;i<m;i++){
            mp[banned[i]]=true;
        }
        int ans=0;
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(!mp[i] && sum+i<=maxSum){
                ans++;
                sum+=i;
            }
            else if(sum+i>maxSum){
                break;
            }

        }
        return ans;
    }
};