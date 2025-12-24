class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int sum=0;
        for(auto x:apple){
            sum+=x;
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        int j=0;
        int op=0;
        while(sum>0){
            sum-=capacity[j++];
            op++;
        }
        return op;
        
    }
};