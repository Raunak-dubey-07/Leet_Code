class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int operations=0;
        for(auto x:mp){
            if(x.second==1){
                return -1;
            }
            if(x.second%3==0){
                operations+=x.second/3;
            }
            else if(x.second%3==1){
                operations+=(x.second/3)-1;
                operations+=2;
            }
            else{
                operations+=(x.second/3);
                operations+=1;
            }
        }
        return operations;
    }
};