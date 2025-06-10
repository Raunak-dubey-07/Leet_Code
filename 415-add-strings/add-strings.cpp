class Solution {
public:
    string addStrings(string num1, string num2) {
       int n1=num1.size();
       int n2=num2.size();
       if(n1>n2){
        int k=n1-n2;
        num2.insert(0,k,'0');
       }
       else{
        int k=n2-n1;
        cout<<k<<endl;
        num1.insert(0,k,'0');
       }
       string ans="";
       //cout<<num1<<endl;
       int i=num1.size()-1;
       //cout<<i<<endl;
       int carey=0;
       while(i>=0){
        int a=num1[i]-'0';
        int b=num2[i]-'0';
       // cout<<a+b<<endl;
        ans.insert(0,1,((a+b+carey)%10+'0'));
        i--;
        carey=(a+b+carey)/10;
       }
       if(carey>0){
        ans.insert(0,1,(carey%10)+'0');
       }
       return ans;
    }
};