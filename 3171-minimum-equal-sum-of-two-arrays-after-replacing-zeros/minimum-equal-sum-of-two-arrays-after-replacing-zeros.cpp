class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        int n=nums1.size();
        int m=nums2.size();
        int z1=0;
        int z2=0;
        for(int i=0;i<n;i++){
            if(nums1[i]==0){
                z1++;
            }
            sum1+=nums1[i];
        }
        for(int i=0;i<m;i++){
            if(nums2[i]==0){
                z2++;
            }
            sum2+=nums2[i];
        }
        if(z1==0){
            if(sum1<sum2 || sum2+z2>sum1){
                return -1;
            }
        }
        if(z2==0){
            if(sum2<sum1 || sum1+z1>sum2){
                return -1;
            }
        }
        return max(sum1+z1,sum2+z2);
    }
};