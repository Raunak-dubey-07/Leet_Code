class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk=numBottles;
        int fill=0;
        while(numBottles>=numExchange){
            numBottles=numBottles-numExchange+1;
            drunk++;
            numExchange++;
        }
        return drunk;
        
    }
};