class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candy(n,1);
        vector<int>flag(n,0);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                flag[i]=1+flag[i+1];
            }
        }
        for(int i=0;i<n;i++){
            cout<<flag[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<ratings.size();i++){
            if((i-1)>=0){
                if(ratings[i]>ratings[i-1] && candy[i]<=candy[i-1]){
                    candy[i]=1+candy[i-1];
                }
            }
            if((i+1)<n){
               if(ratings[i]>ratings[i+1] ){
                    candy[i]=max(candy[i],2+flag[i+1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<candy[i]<<" ";
        }
        cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=candy[i];
        }
        return ans;
        
    }
};