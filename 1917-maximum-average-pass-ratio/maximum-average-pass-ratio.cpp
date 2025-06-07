class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       using PI = pair<double,pair<double, double>>;
       
    priority_queue<PI> pq;
    for(int i=0;i<classes.size();i++){
         double avg=((double)(classes[i][0]+1)/(double)(classes[i][1]+1))-(double)(classes[i][0]/(double)classes[i][1]);
         //cout<<avg<<endl;
         pq.push({avg,{classes[i][0],classes[i][1]}});
    }
    while(extraStudents){
       double stu= pq.top().second.first+1;
       double total=pq.top().second.second+1;
       //cout<<stu<<" "<<total<<endl;
       //cout<<pq.top().first<<endl;
      
       extraStudents--;
       double ratio=((stu+1)/(total+1))-(stu/total);
        pq.pop();
       pq.push({ratio,{stu,total}});
    }
    double total=0;
    while(!pq.empty()){
       // cout<<(float)pq.top().second.first/(float)pq.top().second.second<<endl;
        total=total+(pq.top().second.first/pq.top().second.second);
        pq.pop();
    }
    return total/classes.size();
    }
};