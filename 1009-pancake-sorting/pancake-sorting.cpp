class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        for(int i=n;i>=1;i--){
            int j=find(arr.begin(),arr.end(),i)-arr.begin();
            if(j!=i-1){
                reverse(arr.begin(),arr.begin()+j+1);
                ans.push_back(j+1);
                reverse(arr.begin(),arr.begin()+i);
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};