class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count=0;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]==9){
                count++;
            }
        }
        if(count==n){
            vector<int>digit((n),0);
            digit.push_back(1);
            sort(digit.begin(),digit.end(),greater<int>());
            return digit;

        }
        else{
        digits[n-1]++;
            if(digits[n-1]==10){
            for(int i=0;i<n;i++){
                   if(digits[i]==10){
                    digits[i]=0;
                    digits[i-1]++;
                    i=0;
                   } 
                }
                return digits;
            }
            else{
                return digits;
            }
        }
        return digits;
        
    }
};