class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>num;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                num.insert(num.begin(),nums[i]);
            }
            else{
                num.push_back(nums[i]);
            }
        }
        return num;

    }
};