class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int>mp;
        int n=position.size();
        for(int i=0;i<n;i++){
            mp[position[i]]=speed[i];
        }
        sort(position.begin(),position.end());
        stack<float>st;
        for(int i=0;i<n;i++){
            int d=target-position[i];
            float t=(float)d/(float)mp[position[i]];
            //cout<<t<<endl;
            while(!st.empty() && t>=st.top()){
                st.pop();
            }
            st.push(t);
        }
        return st.size();
    }
};
