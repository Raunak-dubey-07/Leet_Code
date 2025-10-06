class Solution {
public:
    int minOperations(int k) {
        int ans=INT_MAX;
        for(int i=0;i<(k+1)/2;i++){
            int x=k/(i+1);
            if(k%(i+1)==0){
                x--;
            }
            //x--;
            ans=min(ans,x+i);
        }
        return ans;
    }
};