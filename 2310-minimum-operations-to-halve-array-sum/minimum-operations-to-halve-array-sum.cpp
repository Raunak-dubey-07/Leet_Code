class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<float>pq;
        double sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        double sum1=sum;
        long long operation=0;
        while(!pq.empty()&&(sum1>sum/2)){
            float a=pq.top();
            pq.pop();
            sum1=sum1-(a/2);
            pq.push(a/2);
            operation++;
        }
        return operation;
        
    }
};