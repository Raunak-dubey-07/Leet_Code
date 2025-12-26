class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        while(i<(int)pushed.size()){
            // cout<<pushed.size()<<endl;
            // cout<<i<<endl;
            if(i<0){
                i++;
            }
            else if(pushed[i]==popped[j]){
                cout<<pushed[i]<<endl;
                pushed.erase(pushed.begin()+i);
                j++;
                i--;
            }
            else{
                i++;
            }
            // cout<<"hii "<<i<<endl;
            // cout<<pushed.size()<<endl;
            // cout<<i<<endl;
            // if(i<pushed.size()){
            //     cout<<"yes<"<<endl;
            // }
        }
        if(pushed.size()==0){
            return true;
        }
        return false;
        
    }
};