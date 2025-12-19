class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices==0 &&cheeseSlices==0){
            return {0,0};
        }
        int Jumbo=0;
        int small=0;
        if(tomatoSlices%2!=0){
            return {};
        }
        while(tomatoSlices>0){
            if((tomatoSlices/2)==cheeseSlices){
                return {Jumbo,tomatoSlices/2};
            }
            tomatoSlices-=4;
            cheeseSlices--;
            Jumbo++;
        }
        return {};
        
    }
};