class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int>mini;
        queue<int>maxi;
        queue<int>equal;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                mini.push(nums[i]);

            }
            else if(nums[i]>pivot){
                maxi.push(nums[i]);
            }
            else{
                equal.push(nums[i]);
            }
        }
        nums.clear();
        while(!mini.empty()){
            nums.push_back(mini.front());
            mini.pop();
        }
         while(!equal.empty()){
            nums.push_back(equal.front());
            equal.pop();
        }
        while(!maxi.empty()){
            nums.push_back(maxi.front());
            maxi.pop();
        }
        
       
        return nums;
        
    }
};