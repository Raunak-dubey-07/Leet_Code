class Solution {
public:
    int minimumBuckets(string hamsters) {
        unordered_map<int,bool>mp;
        long long ans=0;
        int n=hamsters.size();
        if(n==1 && hamsters[0]=='H'){
            return -1;
        }
        for(int i=0;i<n;i++){
            if(hamsters[i]=='H'){
                if(i==0){
                    if(hamsters[i+1]=='H'){
                        return -1;
                    }
                    if(!mp[i+1]){
                        mp[i+1]=true;
                        ans++;
                    }
                }
                else if(i==n-1){
                    if(hamsters[i-1]=='H'){
                        return -1;
                    }
                    if(!mp[i-1]){
                        mp[i-1]=true;
                        ans++;
                    }
                }
                else{
                    if(hamsters[i-1]=='H' && hamsters[i+1]=='H'){
                        return -1;
                    }
                    if(!mp[i-1] && !mp[i+1]){
                        mp[i+1]=true;
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};