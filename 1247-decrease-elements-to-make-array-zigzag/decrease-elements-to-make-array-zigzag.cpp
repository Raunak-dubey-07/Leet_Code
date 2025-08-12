class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int op1=0;
        int op2=0;
        int n=nums.size();
        vector<int>dup=nums;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(i>0 && nums[i-1]>=nums[i]){
                    op1+=(nums[i-1]-nums[i])+1;
                    nums[i-1]=nums[i]-1;
                }
                if(i<n-1 && nums[i+1]>=nums[i]){
                    op1+=(nums[i+1]-nums[i])+1;
                    nums[i+1]=nums[i]-1;
                }
                
            }
        
        }
        nums=dup;
        for(int i=0;i<n;i++){
            if(i%2!=0){
                if(i>0 && nums[i-1]>=nums[i]){
                    cout<<i<<" "<<nums[i]<<endl;
                    op2+=(nums[i-1]-nums[i])+1;
                    cout<<op2<<endl;
                    nums[i-1]=nums[i]-1;
                }
                if(i<n-1 && nums[i+1]>=nums[i]){
                    cout<<i<<" "<<nums[i]<<endl;
                    op2+=(nums[i+1]-nums[i])+1;
                    cout<<op2<<endl;
                    nums[i+1]=nums[i]-1;
                }
                
            }
        
        }
        return min(op1,op2);
    }
};