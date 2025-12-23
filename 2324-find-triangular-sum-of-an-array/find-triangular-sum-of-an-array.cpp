class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (nums.size() > 1) {
            vector<int> arr;
            for (int i = 0; i + 1 < nums.size(); i++) {
                
                arr.push_back((nums[i] + nums[i + 1])%10);
            }
            nums = arr;
        }
        return nums[0];
    }
};
//     while (1) {
//         vector<int> arr;
//         for (int i = 0; i < nums.size() - 1; i++) {
//             cout << nums[i] << endl;
//         }
//         for (int i = 0; i < nums.size() - 1; i++) {
//             cout << nums[i] << endl;
//             arr.push_back(nums[i] + nums[i + 1]);
//         }
//         if (arr.size() == 1) {
//             return arr[0];
//         }
//         nums = arr;
//     }
// }