class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        int j = 0;
        while (i < n && nums[i] % 2 == 0) {
            i++;
        }
        j = i;
        while (j < n && k) {
            if (nums[j] % 2 != 0) {
                k--;
                if (k == 0) {
                    break;
                }
            }
            j++;
        }
    while (i < n && j < n) {
        if (i < n && j < n) {
            int l = i - 1;
            int r = j + 1;
            int left = 0;
            int right = 0;
            while (l >= 0 && nums[l] % 2 == 0) {
                l--;
                left++;
            }
            while (r < n && nums[r] % 2 == 0) {
                right++;
                r++;
            }
            cout<<left<<" "<<right<<endl;
            ans += (left + 1) * (right + 1);
        }
        i++;
        j++;
        while(i<n && nums[i]%2==0){
            i++;
        }
        while(j<n && nums[j]%2==0){
            j++;
        }
       
    }
    return ans;
}
}
;