class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count =0;
        while(target>startValue){
            if(target%2!=0){
                target++;
                count++;
            }
            target=target/2;
            count++;
        }
        count=count+(startValue-target);
        return count;
        
    }
};