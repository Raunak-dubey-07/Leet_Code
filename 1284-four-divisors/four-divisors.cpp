class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int div = 2;
            long long sum = 1+nums[i];
            for (int j = 2; j * 2 <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    div++;
                    sum += j;
                    if(div>4){
                        break;
                    }
                }
            }
            if (div == 4) {
                ans += sum;
            }
        }
        return ans;
    }
};