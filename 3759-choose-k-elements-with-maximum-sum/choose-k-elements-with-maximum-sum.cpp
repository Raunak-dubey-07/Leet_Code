class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],i});
        }
        vector<long long>ans(n,0);
        sort(vec.begin(),vec.end());
        sort(nums1.begin(),nums1.end());
        long long sum=0;
        long long sum1=0;
       priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            if(i!=0 && nums1[i]==nums1[i-1]){
                ans[vec[i].second]=sum1;
            }
            else{
                ans[vec[i].second]=sum;
                sum1=sum;

            }
            if(pq.size()<k){
                sum+=nums2[vec[i].second];
                pq.push(nums2[vec[i].second]);
            }
            else{
                if(pq.top()<nums2[vec[i].second]){
                    sum-=pq.top();
                    pq.pop();
                    sum+=nums2[vec[i].second];
                    pq.push(nums2[vec[i].second]);
                }
            
            }
            

        }
        return ans;
    }
};