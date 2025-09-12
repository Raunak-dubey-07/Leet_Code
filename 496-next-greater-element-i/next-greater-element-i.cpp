class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        int m=nums1.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n && nums2[i]>nums2[j] ){
                j++;
            }
            if(j==n){
                mp[nums2[i]]=-1;
                //cout<<nums2[i]<<endl;
            }
            else{
                mp[nums2[i]]=nums2[j];
               // cout<<nums2[i]<<" "<<nums2[j]<<endl;
            }
        }
        for(int i=0;i<m;i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
        
    }
};