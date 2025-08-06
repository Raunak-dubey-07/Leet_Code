class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        

        vector<long long>ans;
        if(finalSum%2!=0){
            return ans;
        }
long long req=finalSum/2;
        long long k=1;
        while(req>0 && req>=k){
            req=req-k;
            ans.push_back(k*2);
            k++;
        }
        if(req!=0){
            ans[ans.size()-1]+=req*2;
        }
        return ans;
        
        
    }
};
