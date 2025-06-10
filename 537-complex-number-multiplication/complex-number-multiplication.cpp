class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        string r="",c="";
        bool flag=false;
        for(int i=0;i<num1.size()-1;i++){
            if(num1[i]=='+'){
                 flag=true;
            }
            else if(!flag){
                //cout<<num1[i]<<endl;
                r.push_back(num1[i]);
            }
            else{
                c.push_back(num1[i]);
            }
        }
        if(r.size()>0)
          r1=stoi(r);
        
      if(c.size()>0)
        c1=stoi(c);
        r="";
        c="";
        flag=false;
         for(int i=0;i<num2.size()-1;i++){
            if(num2[i]=='+'){
               flag=true;
            }
            else if(!flag){
                r.push_back(num2[i]);
            }
            else{
                c.push_back(num2[i]);
            }
        }
       if(r.size()>0)
        r2=stoi(r);
        
       if(c.size()>0)
        c2=stoi(c);
       //cout<<r1<<" "<<r2<<endl;
       //cout<<c1<<" "<<c2<<endl;
       
        int r3=(r1*r2)+((-1)*(c1*c2));
        int c3=(r1*c2)+(r2*c1);
        //cout<<c1<<endl;
        string ans=(to_string(r3)+'+'+to_string(c3)+'i');
        return ans;
    }
};