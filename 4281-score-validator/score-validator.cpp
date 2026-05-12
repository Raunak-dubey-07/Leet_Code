class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n=events.size();
        int score=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(events[i]=="W"){
                count++;
            }
            else if(events[i]=="WD"|| events[i]=="NB"){
                score++;
            }
            else{score+=stoi(events[i]);
                
            }
            if(count==10){
                break;
            }
        }
        return {score,count};
        
    }
};