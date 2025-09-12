class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
            }
        }
        int m=nums1.size();
        for(int i=0;i<m;i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
        
    }
};