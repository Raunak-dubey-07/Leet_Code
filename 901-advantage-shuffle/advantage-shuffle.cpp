class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<pair<int,int>>sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({nums2[i],i});
        }
        sort(sorted.begin(),sorted.end(),greater<pair<int,int>>());
        sort(nums1.begin(),nums1.end(),greater<int>());
        int h=n-1;
        int l=0;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            if(nums1[l]>sorted[i].first){
                res[sorted[i].second]=nums1[l++];
            }
            else{
                res[sorted[i].second]=nums1[h--];
            }
        }
        return res;
    }
};