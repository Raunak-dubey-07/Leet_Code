class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hours=hour*30;
        double min=minutes*6;
        hours+=minutes*0.5;
        if(hours>=360){
            hours-=360;
        }
         if(min>=360){
            min-=360;
        }
        double x=abs(hours-min);
        cout<<x<<endl;
        double y=abs((360-hours)-(360-min));
        cout<<y<<endl;
       double mini = (x < y) ? x : y;
       double mini2=360-mini;
        return (mini < mini2) ? mini : mini2;
    }
};