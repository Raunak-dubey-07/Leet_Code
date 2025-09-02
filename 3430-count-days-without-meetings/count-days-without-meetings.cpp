class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(),meetings.end());
    int maxi=0;
    int n=meetings.size();
    int ans=meetings[0][0]-1;
    maxi=max(maxi,meetings[0][1]);
    //cout<<maxi<<endl;
    for(int i=1;i<n;i++){
        if(meetings[i][0]>maxi){
           ans+=(meetings[i][0]-maxi-1);
           //cout<<meetings[i][1]<<endl;
        }
         maxi=max(maxi,meetings[i][1]);
    }
    //cout<<maxi<<endl;
    ans+=(days-maxi);
    return ans;
    }
};