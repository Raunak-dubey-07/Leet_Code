class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int maxi=max(a,max(b,c));
        int x=0;
        int y=0;
        int ans=0;
        if(maxi==a){
            x=b;
            y=c;
        }
        else if(maxi==b){
            x=a;
            y=c;
        }
        else{
            x=a;
            y=b;
        }
        while(x+y>maxi && x>0 && y>0){
            x=x-1;
            y=y-1;
            ans++;
        }
        if(x+y<=maxi){
            return x+y+ans;
        }
        return maxi+ans;

        
    }
};