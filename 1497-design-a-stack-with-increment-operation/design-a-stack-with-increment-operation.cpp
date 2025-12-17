class CustomStack {
public:
vector<int>arr;
int top;
    CustomStack(int maxSize) {
        cout<<"hi"<<endl;
        arr.resize(maxSize); 
        top= -1;  
    }
    
    void push(int x) {
        if(top==-1|| top<(arr.size()-1)){
            top++;
            arr[top]=x;
        }
        
    }
    
    int pop() {
        if(top!=-1){
            int t=arr[top--]; 
            return t;
        }
        return -1; 
    }
    
    void increment(int k, int val) {
       for (int i = 0; i < min(k, top + 1); i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */