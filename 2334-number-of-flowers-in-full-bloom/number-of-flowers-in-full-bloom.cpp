class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m=flowers.size();
        int n=people.size();
        vector<int>start;
        vector<int>end;
        vector<int>result;
        for(int i=0;i<m;i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i=0;i<n;i++){
            int x=upper_bound(start.begin(),start.end(),people[i])-start.begin();
        int y=lower_bound(end.begin(),end.end(),people[i])-end.begin();
        cout<<people[i]<<" "<<x<<" "<<y<<endl;
        result.push_back(x-y);
        }
        return result;
    }
};