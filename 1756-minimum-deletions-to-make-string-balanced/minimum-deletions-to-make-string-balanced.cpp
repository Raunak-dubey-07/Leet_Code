class Solution {
public:
    int minimumDeletions(string s) {
         int ones = 0;
    int flips = 0;

    for(char c : s){
        if(c == 'b'){
            ones++;
        } else {
            flips = min(flips + 1, ones);
        }
    }
    return flips;
    }
};