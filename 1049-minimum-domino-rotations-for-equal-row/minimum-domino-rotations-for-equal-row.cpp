class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        unordered_map<int,int>equal;
        int n=bottoms.size();
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                equal[tops[i]]++;
            }
            else{
                mp1[tops[i]]++;
                mp2[bottoms[i]]++;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            // cout<<mp1[tops[i]]<<" "<<mp2[bottoms[i]]<<" "<<equal[tops[i]]<<endl;
           // cout<<mp2[bottoms[i]]<<endl;
            if(mp1[tops[i]]==n || mp2[bottoms[i]]==n){
                return 0;
            }
            if((mp1[tops[i]]+mp2[tops[i]]+equal[tops[i]])==n){
                ans=min(ans,mp2[tops[i]]);
            }
             if((mp2[bottoms[i]]+mp1[bottoms[i]]+equal[bottoms[i]])==n){
                ans=min(ans,mp1[bottoms[i]]);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

        
    }
};