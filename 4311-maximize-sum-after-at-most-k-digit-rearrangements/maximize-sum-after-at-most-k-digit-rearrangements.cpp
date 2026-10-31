class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end(), greater<int>());

        long long sum = 0;
        vector<int>gain;

        for (int i = 0; i < nums.size(); i++) {
                string s = to_string(nums[i]);
                sort(s.begin(), s.end(), greater<char>());
                gain.push_back(stoi(s)-nums[i]);
                //cout<<gain.back()<<endl;
            sum+=nums[i];
        }
        sort(gain.begin(),gain.end(),greater<int>());
        for(int i=0;i<k;i++){
            if(gain[i]<0){
                break;
            }
            sum+=gain[i];
        }
        return sum;
    }
};