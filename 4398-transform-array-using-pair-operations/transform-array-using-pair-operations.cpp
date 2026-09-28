class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n=source.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(source[i]-target[i]);
        }
        if(ans==0){
            return true;
        }
        return false;
    }
};