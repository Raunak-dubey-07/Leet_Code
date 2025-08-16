class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;

        }
        float x=float(log(n)/log(4));
       
         
        if(x==round(x)){
            return true;
        }
        return false;
         
        
    }
};