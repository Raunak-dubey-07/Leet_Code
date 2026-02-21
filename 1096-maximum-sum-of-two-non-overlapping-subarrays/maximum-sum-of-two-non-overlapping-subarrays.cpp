class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int i=0;
        int res=0;
        while(i+(firstLen+secondLen-1)<n){
            int j=i+firstLen;
            int sum1=prefix[i+firstLen-1];
            if(i!=0){
                sum1=sum1-prefix[i-1];
            }
            while(j+secondLen-1<n){
                int sum2=prefix[j+secondLen-1]-prefix[j-1];
                res=max(res,sum1+sum2);
                // cout<<"i "<<i<<endl;
                // cout<<"j "<<j<<endl;
                // cout<<res<<endl;
                j++;
            }
            i++;
        }
        
        i=0;
        while(i+(firstLen+secondLen-1)<n){
            int j=i+secondLen;
            int sum1=prefix[i+secondLen-1];
            if(i!=0){
                sum1=sum1-prefix[i-1];
            }
            while(j+firstLen-1<n){
                int sum2=prefix[j+firstLen-1]-prefix[j-1];
                res=max(res,sum1+sum2);
                j++;
            }
            i++;

        }
        return res;

        
    }
};