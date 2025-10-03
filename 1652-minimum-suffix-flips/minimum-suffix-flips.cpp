class Solution {
public:
    int minFlips(string target) {
        int n=target.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(target[i]=='0'){
                c++;
            }
        }
        if(c==n){
            return 0;
        }
        int op=0;
        int j=n-1;
        while(j>=0 && target[j]=='1'){
            j--;
            op=1;
        }
        int i=j;
        //cout<<i<<endl;
        while(i>=0){
            if(target[i]=='0'){
                i--;
                continue;
            }
            while(i>=0 && target[i]=='1'){
                i--;
            }
            op+=2;
        }
        
        return op;
        
    }
};